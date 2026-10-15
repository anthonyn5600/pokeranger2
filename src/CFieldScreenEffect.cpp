#include "field/CFieldScreenEffect.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "CameraController.hpp"
#include "FieldScreenEffectManage.hpp"

BOOL CFieldSEFFog::s_dirty;
int CFieldSEFFog::s_density;
int CFieldScreenEffectObjectBase::s_frameStep;
static UnkStruct_0200D3F8_Target *sCameraTarget;
static Point2D sCameraPos;
Point2D CFieldScreenEffectObjectBase::s_scroll;
int CFieldSEFFog::s_color[3];

int CFieldScreenEffectObjectBase::Update(int fps)
{
    switch (m_state) {
    case STATE_FADE_START:
        if (m_fadeIn > 0) {
            m_state = STATE_FADE_IN;
        } else {
            m_state = STATE_SHOWN;
            if (m_hold > 0) {
                m_timer += s_frameStep;
                if (m_timer >= m_hold) {
                    m_timer = 0;
                    m_state = STATE_FADE_OUT;
                }
            }
            break;
        }
    case STATE_FADE_IN:
        m_timer += s_frameStep;
        if (m_timer >= m_fadeIn) {
            m_timer = 0;
            m_state = STATE_SHOWN;
        }
        break;
    case STATE_SHOWN:
        if (m_hold > 0) {
            m_timer += s_frameStep;
            if (m_timer >= m_hold) {
                m_timer = 0;
                m_state = STATE_FADE_OUT;
            }
        }
        break;
    case STATE_FADE_OUT:
        m_timer += s_frameStep;
        if (m_timer >= m_fadeOut) {
            m_timer = 0;
            m_state = STATE_FADE_END;
        }
        break;
    case STATE_FADE_END:
        m_state = STATE_DONE;
        break;
    case STATE_DONE:
        break;
    }

    if (m_state == STATE_SHOWN) {
        m_alpha = FX32_ONE;
    } else if (m_state == STATE_FADE_IN) {
        m_alpha = (m_timer << FX32_SHIFT) / m_fadeIn;
    } else if (m_state == STATE_FADE_OUT) {
        m_alpha = ((m_fadeOut - m_timer) << FX32_SHIFT) / m_fadeOut;
    } else {
        m_alpha = 0;
    }

    return m_state;
}

BOOL CFieldScreenEffectObjectBase::Start(int fadeIn, int hold, int fadeOut)
{
    m_fadeIn = fadeIn;
    m_hold = hold;
    m_fadeOut = fadeOut;

    if (m_state == STATE_FADE_IN) {
        return TRUE;
    }

    if (m_state == STATE_SHOWN) {
        m_timer = 0;
        return TRUE;
    }

    if (m_state == STATE_FADE_OUT) {
        if (fadeIn > 0) {
            m_state = STATE_FADE_IN;
            m_fadeIn = fadeIn;
            m_timer = (fadeIn * m_alpha) >> FX32_SHIFT;
        } else {
            m_state = STATE_SHOWN;
            m_alpha = FX32_ONE;
        }
        return TRUE;
    }

    if (fadeIn > 0) {
        m_state = STATE_FADE_START;
        m_alpha = 0;
    } else {
        m_state = STATE_SHOWN;
        m_alpha = FX32_ONE;
    }
    m_timer = 0;
    return TRUE;
}

BOOL CFieldScreenEffectObjectBase::Stop(int fadeOut)
{
    m_state = fadeOut > 0 ? STATE_FADE_OUT : STATE_DONE;
    m_timer = 0;
    m_fadeOut = fadeOut;
    return TRUE;
}

void CFieldScreenEffectObjectBase::SetupMatrix(Camera2D *camera)
{
    G3_RestoreMtx(0);
    G3_Identity();
    G3_Translate(FX32_CONST(128), FX32_CONST(96), 0);
    fx32 scale = 1 << camera->unk_26;
    G3_Scale(scale, scale, scale);
}

void CFieldScreenEffectObjectBase::InitScroll()
{
    sCameraTarget = CGame::GetInstance()->m_cameraController->m_target;
    if (sCameraTarget != NULL) {
        Point2D pos = *(Point2D *)&sCameraTarget->x;
        sCameraPos = pos;
    } else {
        sCameraPos.x = 0;
        sCameraPos.y = 0;
        s_scroll.x = 0;
        s_scroll.y = 0;
    }
}

void CFieldScreenEffectObjectBase::UpdateScroll()
{
    if (sCameraTarget == NULL) {
        sCameraTarget = CGame::GetInstance()->m_cameraController->m_target;
        if (sCameraTarget != NULL) {
            Point2D pos = *(Point2D *)&sCameraTarget->x;
            sCameraPos = pos;
        }
    }

    UnkStruct_0200D3F8_Target *target = sCameraTarget;
    if (target == NULL) {
        return;
    }

    Point2D cur = *(Point2D *)&target->x;
    s_scroll = cur;
    s_scroll -= sCameraPos;
    Point2D pos = *(Point2D *)&target->x;
    sCameraPos = pos;
}

void FieldScreenEffectManage::Alloc(int count)
{
    Free();
    m_count = count;
    m_effects = new CFieldScreenEffectObjectBase *[m_count];
    for (int i = 0; i < m_count; i++) {
        m_effects[i] = NULL;
    }
    CFieldScreenEffectObjectBase::InitScroll();
}

void FieldScreenEffectManage::Free()
{
    if (m_effects != NULL) {
        for (int i = 0; i < m_count; i++) {
            if (m_effects[i] != NULL) {
                SAFE_DELETE(m_effects[i]);
            }
        }
        SAFE_DELETE_ARRAY(m_effects);
    }
    m_count = 0;
}

void FieldScreenEffectManage::Update(int fps)
{
    CFieldScreenEffectObjectBase::UpdateScroll();
    CFieldScreenEffectObjectBase::s_frameStep = 60 / fps;
    for (int i = 0; i < m_count; i++) {
        if (m_effects[i] != NULL) {
            if (m_effects[i]->Update(fps) == CFieldScreenEffectObjectBase::STATE_DONE) {
                SAFE_DELETE(m_effects[i]);
            }
        }
    }
}

void FieldScreenEffectManage::Draw(Camera2D *camera)
{
    for (int i = 0; i < m_count; i++) {
        if (m_effects[i] != NULL) {
            m_effects[i]->Draw(camera);
        }
    }
}

int FieldScreenEffectManage::Add(CFieldScreenEffectObjectBase *effect)
{
    if (m_effects != NULL) {
        for (int i = 1; i < m_count; i++) {
            if (m_effects[i] == NULL) {
                m_effects[i] = effect;
                return i;
            }
        }
    }
    return -1;
}

int FieldScreenEffectManage::SetPrimary(CFieldScreenEffectObjectBase *effect)
{
    if (m_effects != NULL) {
        if (m_effects[0] != NULL) {
            SAFE_DELETE(m_effects[0]);
        }
        m_effects[0] = effect;
        return 0;
    }
    return -1;
}

void FieldScreenEffectManage::ClearSecondary()
{
    if (m_effects == NULL) {
        return;
    }
    for (int i = 1; i < m_count; i++) {
        if (m_effects[i] != NULL) {
            SAFE_DELETE(m_effects[i]);
        }
    }
}

void FieldScreenEffectManage::ClearPrimary()
{
    if (m_effects != NULL && m_effects[0] != NULL) {
        SAFE_DELETE(m_effects[0]);
    }
}

CFieldScreenEffectObjectBase *FieldScreenEffectManage::CreateEffect(int type)
{
    if (type > 0) {
        switch (type) {
        case 1:
            return new CFieldSEFHinoko(TRUE);
        case 2:
            return new CFieldSEFRain();
        case 3:
            return new CFieldSEFKomorebi();
        case 4:
        case 5:
        case 6:
        case 7:
        case 16:
            return new CFieldSEFFog(type);
        case 8:
            return new CFieldSEFSandStorm();
        case 9:
            return new CFieldSEFDokarimo();
        case 10:
            return new CFieldSEFTheWater(type);
        case 12:
            return new CFieldSEFHinoko(FALSE);
        case 13:
            return new CFieldSEFWarning();
        case 14:
            return new CFieldSEFSnow();
        case 11:
        case 15:
            return new CFieldSEFDarkness(type);
        }
    }
    return NULL;
}

int FieldScreenEffectManage::FindByType(int type)
{
    if (type > 0 && m_effects != NULL) {
        for (int i = 0; i < m_count; i++) {
            if (m_effects[i] != NULL && type == m_effects[i]->GetType()) {
                return i;
            }
        }
        return Add(CreateEffect(type));
    }
    return -1;
}

int FieldScreenEffectManage::sub_02035D38(int type)
{
    if (type > 0 && m_effects != NULL) {
        if (m_effects[0] != NULL && type == m_effects[0]->GetType()) {
            return 0;
        }
        return SetPrimary(CreateEffect(type));
    }
    return -1;
}

BOOL FieldScreenEffectManage::StartEffect(int type, int fadeIn, int hold, int fadeOut)
{
    if (type > 0 && m_effects != NULL) {
        for (int i = 0; i < m_count; i++) {
            if (m_effects[i] != NULL && type == m_effects[i]->GetType()) {
                m_effects[i]->Start(fadeIn, hold, fadeOut);
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL FieldScreenEffectManage::StopEffect(int type, int fadeOut)
{
    if (type > 0 && m_effects != NULL) {
        for (int i = 0; i < m_count; i++) {
            if (m_effects[i] != NULL && type == m_effects[i]->GetType()) {
                m_effects[i]->Stop(fadeOut);
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL FieldScreenEffectManage::IsEffectActive(int type)
{
    if (type > 0 && m_effects != NULL) {
        for (int i = 0; i < m_count; i++) {
            if (m_effects[i] != NULL && type == m_effects[i]->GetType()) {
                if (m_effects[i]->m_state != CFieldScreenEffectObjectBase::STATE_DONE) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL FieldScreenEffectManage::sub_02035F50(int type, int arg)
{
    if (type != 3) {
        return FALSE;
    }
    if (type > 0 && m_effects != NULL) {
        for (int i = 0; i < m_count; i++) {
            if (m_effects[i] != NULL && type == m_effects[i]->GetType()) {
                ((CFieldSEFKomorebi *)m_effects[i])->sub_02037330(arg);
                return TRUE;
            }
        }
    }
    return FALSE;
}
