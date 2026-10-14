#include "battle/CBattleAttackEffect.hpp"

#include "UnkStruct_02044464.hpp"
#include "battle/CBattleAttackEffectData.hpp"
#include "battle/CBattleEnemy.hpp"
#include "file/CNANRFile.hpp"
#include "file/CNCERFile.hpp"

CBattleAttackEffect::CBattleAttackEffect(u8 index)
{
    m_index = index;
    unk_184 = NULL;
    unk_190 = NULL;
    unk_18E = 1;
    m_sphere.m_color = 0x7C00;
    m_sphere.m_z = 0x400;
    m_sphere.m_alpha = 8;
    m_sphere.m_circle.r = 0x8000;
    m_sphere.m_polygonID = 0x3F;
    m_line.m_color = 0x7C00;
    m_line.m_z = 0x401;
    m_line.m_alpha = 0x1F;
    m_line.m_polygonID = 0x3E;
}

CBattleAttackEffect::~CBattleAttackEffect()
{
}

void CBattleAttackEffect::vfunc_08()
{
    if (!HasData()) {
        return;
    }
    CBattleEnemy *target = unk_190;
    if (target != NULL) {
        switch (unk_194) {
        case 0:
            if (!target->HasData()) {
                ov1_02127300();
                return;
            }
            break;
        case 1:
            if (!target->IsAlive()) {
                ov1_02127300();
                return;
            }
            break;
        case 2:
            if (!target->HasData()) {
                ov1_02127300();
                return;
            }
            break;
        }
    }
    unk_188++;
    if (!HasData()) {
        return;
    }
    UpdateMotion();
    sub_020123AC();
    UpdateJump();
    UpdateDirection();
    NNS_G2dTickCellAnimation(&m_cellAnim, FX32_ONE);
    unk_18A = *(const u16 *)m_cellAnim.animCtrl.pCurrent->pContent;
    UpdateAlphaTween();
    UpdateScaleTween();

    Point2D pos;
    pos.x = m_motion.m_pos.x;
    pos.y = m_motion.m_pos.y - (m_bobHeight + (unk_8C + m_jumpHeight));
    m_sprite->SetPos(pos);
    if (unk_190 != NULL) {
        m_sprite->SetPos(m_motion.GetPos() + unk_190->m_motion.GetPos());
    }
    if (unk_184->unk_18->unk_04 == 2) {
        if (unk_18C != ov1_02127484(m_dir)) {
            unk_18C = ov1_02127484(m_dir);
            ov1_021273A0(unk_18D, unk_18C);
        }
    }

    UnkStruct_0212E008 *entry = unk_184->unk_18;
    Circle circle = entry->GetCircle();
    fx32 scaleX = unk_11C.value;
    circle.pos.x = FX32_MUL(circle.pos.x, scaleX);
    fx32 scaleY = unk_134.value;
    circle.pos.y = FX32_MUL(circle.pos.y, scaleY);
    if (entry->unk_04 == 1) {
        circle.pos.x = FX32_MUL(circle.pos.x, FX_CosIdx(m_dir));
        circle.pos.y = FX32_MUL(circle.pos.y, FX_SinIdx(m_dir));
    }
    circle.r = FX32_MUL(circle.r, MATH_MIN(scaleX, scaleY));
    circle.pos += m_sprite->GetPos();
    m_sphere.SetCircle(circle);
}

void CBattleAttackEffect::ov1_02126F90()
{
    if (!HasData()) {
        return;
    }
    CBattleEnemy *target = unk_190;
    if (target != NULL && unk_194 == 1) {
        if (target->unk_18C == 4 || unk_184->m_script == NULL) {
            return;
        }
        ScriptVM_Run(&m_vm, 0xFFFFF);
    } else {
        if (unk_184->m_script == NULL) {
            return;
        }
        ScriptVM_Run(&m_vm, 0xFFFFF);
    }
}

void CBattleAttackEffect::vfunc_0C(Camera2D *camera)
{
    CActorData *data = m_data;
    if (unk_184->unk_18->unk_02 == 0) {
        return;
    }
    CActorAnim *anim = data->GetAnim(unk_18D);
    CSoftwareSprite *sprite = m_sprite;
    sprite->unk_2C = (UnkClass_CPrimitive_ImageProxy *)anim->image;
    sprite->unk_30 = NULL;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
    sprite->m_cellDataIdx = unk_18A;
    sprite->m_alpha = unk_108.value;
    sprite->m_scale[0] = unk_11C.value;
    sprite->m_scale[1] = unk_134.value;
    if (unk_184->unk_18->unk_04 == 1) {
        sprite->m_rotAngle = m_dir;
    }
    *(u16 *)unk_06 = sprite->Render(camera);
}

void CBattleAttackEffect::vfunc_10(Camera2D *camera)
{
    if ((unk_43C & 2) && IsUnk100Clear()) {
        CPrimitive *sphere = &m_sphere;
        sphere->Render(camera);
    }
}

void CBattleAttackEffect::ov1_021270FC(CBattleAttackEffectData *data)
{
    SetData(data);
    unk_184 = data;
    unk_188 = 0;
    ov1_021273A0(7, 0);
    ScaleTo(0, FX32_ONE, FX32_ONE);
    FadeAlpha(0, 0x1F);
    m_sprite->m_rotAngle = 0;
    SetDir(0);
    FaceMoveDir();
    Circle circle = data->unk_18->GetCircle();
    if (circle.r == 0) {
        ov1_02127388(FALSE);
    } else {
        ov1_02127388(TRUE);
    }
    m_motion.m_mode = 0;
    Jump(0, 1);
    sub_020127D0(0, 0);
    unk_18A = 0;
    unk_18C = 0;
    unk_18D = 7;
    if (data->m_script == NULL) {
        return;
    }
    ScriptVM_Init(&m_vm, m_stack, 0x80);
    *--m_vm.unk_04 = m_index;
    ScriptVM_CallFunction(&m_vm, data->m_script, "initialize", 1);
    *--m_vm.unk_04 = m_index;
    ScriptVM_Start(&m_vm, data->m_script, "proc");
}

void CBattleAttackEffect::ov1_02127280()
{
    ClearData();
}

void CBattleAttackEffect::ov1_0212728C(CBattleEnemy *target, int mode)
{
    if (HasData()) {
        unk_190 = target;
        unk_194 = mode;
    }
}

void CBattleAttackEffect::ov1_021272AC()
{
    if (unk_184 == NULL || unk_184->m_script == NULL) {
        return;
    }
    ScriptVM_Reset(&m_vm);
    *--m_vm.unk_04 = m_index;
    ScriptVM_Start(&m_vm, unk_184->m_script, "vanish");
}

void CBattleAttackEffect::ov1_02127300()
{
    if (unk_184 != NULL && unk_184->m_script != NULL) {
        ScriptVM_Reset(&m_vm);
        *--m_vm.unk_04 = m_index;
        ScriptVM_CallFunction(&m_vm, unk_184->m_script, "terminate", 1);
    }
    ov1_02127280();
    unk_188 = 0;
    unk_190 = NULL;
}

void CBattleAttackEffect::ov1_02127370(BOOL arg0)
{
    if (arg0) {
        m_flags &= ~0x200;
    } else {
        m_flags |= 0x200;
    }
}

void CBattleAttackEffect::ov1_02127388(BOOL arg0)
{
    if (arg0) {
        m_flags &= ~0x100;
    } else {
        m_flags |= 0x100;
    }
}

void CBattleAttackEffect::ov1_021273A0(u8 anim, u16 seq)
{
    const NNSG2dAnimSequence *sequence = NNS_G2dGetAnimSequenceByIdx(unk_184->m_nanr[anim]->unk_B8, seq);
    CActorAnim *actorAnim = unk_184->GetAnim(anim);
    NNS_G2dInitCellAnimation(&m_cellAnim, sequence, actorAnim != NULL ? actorAnim->cells->unk_B8 : NULL);
    m_cellAnim.animCtrl.bActive = TRUE;
    unk_18D = anim;
}

void CBattleAttackEffect::ov1_02127408(u8 anim)
{
    if (unk_184->unk_18->unk_04 == 2) {
        unk_18C = ov1_02127484(m_dir);
        ov1_021273A0(anim, unk_18C);
    } else {
        ov1_021273A0(anim, 0);
    }
}

void CBattleAttackEffect::ov1_02127454(int action, u32 sub)
{
    ov1_02127408(unk_184->GetAnimId(action, sub));
}

BOOL CBattleAttackEffect::ov1_0212747C()
{
    return m_cellAnim.animCtrl.bActive;
}

int CBattleAttackEffect::ov1_02127484(u16 dir)
{
    if (dir < 0x4000) {
        return 3;
    }
    if (dir < 0x8000) {
        return 0;
    }
    if (dir < 0xC000) {
        return 1;
    }
    return 2;
}
