#include "FieldEffectFactorySet.hpp"
#include "common.hpp"
#include "field/CFieldEffectBlackStoneAura.hpp"
#include "field/CFieldEffectBloom.hpp"
#include "field/CFieldEffectBullet.hpp"
#include "field/CFieldEffectBush.hpp"
#include "field/CFieldEffectCellAnime.hpp"
#include "field/CFieldEffectCharge.hpp"
#include "field/CFieldEffectDarkCloud.hpp"
#include "field/CFieldEffectDarkShadow.hpp"
#include "field/CFieldEffectDarknessClear.hpp"
#include "field/CFieldEffectExplosion.hpp"
#include "field/CFieldEffectFire.hpp"
#include "field/CFieldEffectFireworks.hpp"
#include "field/CFieldEffectFlash.hpp"
#include "field/CFieldEffectFlowerStorm.hpp"
#include "field/CFieldEffectFogcut.hpp"
#include "field/CFieldEffectFuwanteWind.hpp"
#include "field/CFieldEffectGlitter.hpp"
#include "field/CFieldEffectJumon.hpp"
#include "field/CFieldEffectLaser.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpuFactory.hpp"
#include "field/CFieldEffectParabolaBullet.hpp"
#include "field/CFieldEffectPoisonGas.hpp"
#include "field/CFieldEffectRisingPhoton.hpp"
#include "field/CFieldEffectSandBurial.hpp"
#include "field/CFieldEffectScatterLeaves.hpp"
#include "field/CFieldEffectSlime.hpp"
#include "field/CFieldEffectSpaceCrevice.hpp"
#include "field/CFieldEffectSpark.hpp"
#include "field/CFieldEffectSpray.hpp"
#include "field/CFieldEffectSpreadSmoke.hpp"
#include "field/CFieldEffectSteam.hpp"
#include "field/CFieldEffectVolcanicSteam.hpp"
#include "field/CFieldEffectWaterGun.hpp"
#include "field/CFieldEffectWaterSplash.hpp"
#include "field/CFieldEffectWaveBullet.hpp"

// Every effect factory of the field, registered with CFieldEffectManage by kind.
struct FieldEffectFactories {
    FieldEffectFactories(CFieldEffectManage *mgr);

    CFieldEffectLaserFactory m_laser; // 0x0
    CFieldEffectBulletFactory m_bullet; // 0x4
    CFieldEffectSpreadSmokeFactory m_spreadSmoke; // 0x8
    CFieldEffectSandBurialFactory m_sandBurial; // 0xC
    CFieldEffectSteamFactory m_steam; // 0x10
    CFieldEffectScatterLeavesFactory m_scatterLeaves; // 0x14
    CFieldEffectChargeFactory m_charge; // 0x18
    CFieldEffectFlashFactory m_flash; // 0x1C
    CFieldEffectWaveBulletFactory m_waveBullet; // 0x20
    CFieldEffectAttackCellAnimeFactory m_attackCellAnime; // 0x24
    CFieldEffectParabolaBulletFactory m_parabolaBullet; // 0x28
    CFieldEffectPoisonGasFactory m_poisonGas; // 0x2C
    CFieldEffectSprayFactory m_spray; // 0x6C
    CFieldEffectNormalCellAnimeFactory m_normalCellAnime; // 0x70
    CFieldEffectFireFactory m_fire; // 0x74
    CFieldEffectSparkFactory m_spark; // 0x78
    CFieldEffectJumonFactory m_jumon; // 0x7C
    CFieldEffectExplosionFactory m_explosion; // 0x80
    CFieldEffectSlimeFactory m_slime; // 0xF4
    CFieldEffectFogcutFactory m_fogcut; // 0x138
    CFieldEffectFlowerStormFactory m_flowerStorm; // 0x13C
    CFieldEffectBushFactory m_bush; // 0x140
    CFieldEffectWaterSplashFactory m_waterSplash; // 0x884
    CFieldEffectManpuFactory m_manpu; // 0x1088
    CFieldEffectBloomFactory m_bloom; // 0x324C
    CFieldEffectDarkCloudFactory m_darkCloud; // 0x32D4
    CFieldEffectFireworksFactory m_fireworks; // 0x32D8
    CFieldEffectDarkShadowFactory m_darkShadow; // 0x32DC
    CFieldEffectDarknessClearFactory m_darknessClear; // 0x32E0
    CFieldEffectWaterGunFactory m_waterGun; // 0x32E4
    CFieldEffectRisingPhotonFactory m_risingPhoton; // 0x32E8
    CFieldEffectVolcanicSteamFactory m_volcanicSteam; // 0x32EC
    CFieldEffectFuwanteWindFactory m_fuwanteWind; // 0x331C
    CFieldEffectGlitterFactory m_glitter; // 0x3358
    CFieldEffectBlackStoneAuraFactory m_blackStoneAura; // 0x3388
    CFieldEffectSpaceCreviceFactory m_spaceCrevice; // 0x33B8
};

STATIC_SIZE_ASSERT(FieldEffectFactories, 0x3414);

FieldEffectFactories::FieldEffectFactories(CFieldEffectManage *mgr)
    : m_poisonGas(mgr)
    , m_explosion(mgr)
    , m_slime(mgr)
    , m_bush(mgr)
    , m_waterSplash(mgr)
{
    mgr->SetFactory(3, &m_laser);
    mgr->SetFactory(2, &m_bullet);
    mgr->SetFactory(10, &m_spreadSmoke);
    mgr->SetFactory(31, &m_sandBurial);
    mgr->SetFactory(9, &m_steam);
    mgr->SetFactory(11, &m_scatterLeaves);
    mgr->SetFactory(34, &m_charge);
    mgr->SetFactory(32, &m_flash);
    mgr->SetFactory(5, &m_waveBullet);
    mgr->SetFactory(6, &m_attackCellAnime);
    mgr->SetFactory(4, &m_parabolaBullet);
    mgr->SetFactory(12, &m_poisonGas);
    mgr->SetFactory(7, &m_spray);
    mgr->SetFactory(14, &m_normalCellAnime);
    mgr->SetFactory(17, &m_fire);
    mgr->SetFactory(15, &m_spark);
    mgr->SetFactory(16, &m_jumon);
    mgr->SetFactory(13, &m_explosion);
    mgr->SetFactory(18, &m_slime);
    mgr->SetFactory(33, &m_fogcut);
    mgr->SetFactory(29, &m_flowerStorm);
    mgr->SetFactory(37, &m_bush);
    mgr->SetFactory(38, &m_waterSplash);
    mgr->SetFactory(1, &m_manpu);
    mgr->SetFactory(19, &m_bloom);
    mgr->SetFactory(20, &m_darkCloud);
    mgr->SetFactory(21, &m_fireworks);
    mgr->SetFactory(22, &m_darkShadow);
    mgr->SetFactory(23, &m_darknessClear);
    mgr->SetFactory(8, &m_waterGun);
    mgr->SetFactory(24, &m_risingPhoton);
    mgr->SetFactory(25, &m_volcanicSteam);
    mgr->SetFactory(26, &m_fuwanteWind);
    mgr->SetFactory(27, &m_glitter);
    mgr->SetFactory(28, &m_blackStoneAura);
    mgr->SetFactory(30, &m_spaceCrevice);
}

FieldEffectFactorySet::FieldEffectFactorySet()
{
    unk_00 = NULL;
}

void FieldEffectFactorySet::Create(CFieldEffectManage *mgr)
{
    Release();
    if (mgr != NULL) {
        unk_00 = new FieldEffectFactories(mgr);
    }
}

void FieldEffectFactorySet::Release()
{
    SAFE_DELETE(unk_00);
}
