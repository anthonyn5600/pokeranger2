#ifndef POKERANGER2_ACTORMOTION_HPP
#define POKERANGER2_ACTORMOTION_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

extern u16 g_actorFps;

// Movement of an actor (CActor::m_motion): position plus the current path (line, curve, direction or orbit).
class ActorMotion {
public:
    enum {
        MODE_NONE,
        MODE_LINEAR,
        MODE_QUADRATIC,
        MODE_CUBIC,
        MODE_DIRECTION,
        MODE_ORBIT,
    };

    ActorMotion();
    ~ActorMotion();
    void Update();
    void MoveLinear(Point2D end, u32 duration);
    void MoveQuadratic(Point2D end, Point2D ctrl, u32 duration);
    void MoveCubic(Point2D end, Point2D ctrl1, Point2D ctrl2, u32 duration);
    void MoveAtSpeed(Point2D end, int speed);
    void MoveInDirection(u16 angle, fx32 speed);
    void Orbit(Point2D center, fx32 radiusX, fx32 radiusY, u16 angle, u16 angleSpeed, u16 tilt);
    void SetX(fx32 x);
    void SetY(fx32 y);
    void SetPos(Point2D pos);

    inline BOOL IsActive()
    {
        return m_mode != MODE_NONE;
    }

    inline Point2D GetPos()
    {
        return m_pos;
    }

public:
    int m_mode;
    u16 m_dir;
    u8 unk_06[0x6];
    u32 m_duration;
    u32 m_frame;
    Point2D m_pos;
    Point2D m_prev;
    Point2D m_start;
    Point2D m_end;
    Point2D m_ctrl1;
    Point2D m_ctrl2;
    u16 m_angle;
    fx32 m_speed;
    Point2D m_center;
    Point2D m_radius;
    u16 m_orbitAngle;
    u16 m_orbitSpeed;
    u16 m_tilt;
};

STATIC_SIZE_ASSERT(ActorMotion, 0x64);

#endif // POKERANGER2_ACTORMOTION_HPP
