#pragma once

// https://github.com/alliedmodders/sourcemod/blob/aae71612731eaa6771067a31f3a7ad34bdb0df28/core/smn_vector.cpp#L40

class CBaseEntity;

#define SET_VECTOR(addr, vec) \
	addr[0] = sp_ftoc(vec.x); \
	addr[1] = sp_ftoc(vec.y); \
	addr[2] = sp_ftoc(vec.z);
#define MAX_TEAMNAME_LENGTH	16
#define MAX_TEAMS			32

template<typename Fn>
Fn GetFunction(void* Base, std::int32_t Index)
{
	std::uintptr_t** uVTablePtr = static_cast<std::uintptr_t**>(Base);
	std::uintptr_t* uVTableFnBase = *uVTablePtr;
	std::uintptr_t uAddress = uVTableFnBase[Index];
	return reinterpret_cast<Fn>(uAddress);
}


#define ACTIVITY_NOT_AVAILABLE		-1

typedef enum
{
	ACT_INVALID = -1,			// So we have something more succint to check for than '-1'
	ACT_RESET = 0,				// Set m_Activity to this invalid value to force a reset to m_IdealActivity
	ACT_IDLE,
	ACT_TRANSITION,
	ACT_COVER,					// FIXME: obsolete? redundant with ACT_COVER_LOW?
	ACT_COVER_MED,				// FIXME: unsupported?
	ACT_COVER_LOW,				// FIXME: rename ACT_IDLE_CROUCH?
	ACT_WALK,
	ACT_WALK_AIM,
	ACT_WALK_CROUCH,
	ACT_WALK_CROUCH_AIM,
	ACT_RUN,
	ACT_RUN_AIM,
	ACT_RUN_CROUCH,
	ACT_RUN_CROUCH_AIM,
	ACT_RUN_PROTECTED,
	ACT_SCRIPT_CUSTOM_MOVE,
	ACT_RANGE_ATTACK1,
	ACT_RANGE_ATTACK2,
	ACT_RANGE_ATTACK1_LOW,		// FIXME: not used yet, crouched versions of the range attack
	ACT_RANGE_ATTACK2_LOW,		// FIXME: not used yet, crouched versions of the range attack
	ACT_DIESIMPLE,
	ACT_DIEBACKWARD,
	ACT_DIEFORWARD,
	ACT_DIEVIOLENT,
	ACT_DIERAGDOLL,
	ACT_FLY,				// Fly (and flap if appropriate)
	ACT_HOVER,
	ACT_GLIDE,
	ACT_SWIM,
	ACT_JUMP,
	ACT_HOP,				// vertical jump
	ACT_LEAP,				// long forward jump
	ACT_LAND,
	ACT_CLIMB_UP,
	ACT_CLIMB_DOWN,
	ACT_CLIMB_DISMOUNT,
	ACT_SHIPLADDER_UP,
	ACT_SHIPLADDER_DOWN,
	ACT_STRAFE_LEFT,
	ACT_STRAFE_RIGHT,
	ACT_ROLL_LEFT,			// tuck and roll, left
	ACT_ROLL_RIGHT,			// tuck and roll, right
	ACT_TURN_LEFT,			// turn quickly left (stationary)
	ACT_TURN_RIGHT,			// turn quickly right (stationary)
	ACT_CROUCH,				// FIXME: obsolete? only used be soldier (the act of crouching down from a standing position)
	ACT_CROUCHIDLE,			// FIXME: obsolete? only used be soldier (holding body in crouched position (loops))
	ACT_STAND,				// FIXME: obsolete? should be transition (the act of standing from a crouched position)
	ACT_USE,
	ACT_SIGNAL1,
	ACT_SIGNAL2,
	ACT_SIGNAL3,

	ACT_SIGNAL_ADVANCE,		// Squad handsignals, specific.
	ACT_SIGNAL_FORWARD,
	ACT_SIGNAL_GROUP,
	ACT_SIGNAL_HALT,
	ACT_SIGNAL_LEFT,
	ACT_SIGNAL_RIGHT,
	ACT_SIGNAL_TAKECOVER,

	ACT_LOOKBACK_RIGHT,		// look back over shoulder without turning around.
	ACT_LOOKBACK_LEFT,
	ACT_COWER,				// FIXME: unused, should be more extreme version of crouching
	ACT_SMALL_FLINCH,		// FIXME: needed? shouldn't flinching be down with overlays?
	ACT_BIG_FLINCH,
	ACT_MELEE_ATTACK1,
	ACT_MELEE_ATTACK2,
	ACT_RELOAD,
	ACT_RELOAD_START,
	ACT_RELOAD_FINISH,
	ACT_RELOAD_LOW,
	ACT_ARM,				// pull out gun, for instance
	ACT_DISARM,				// reholster gun
	ACT_DROP_WEAPON,
	ACT_DROP_WEAPON_SHOTGUN,
	ACT_PICKUP_GROUND,		// pick up something in front of you on the ground
	ACT_PICKUP_RACK,		// pick up something from a rack or shelf in front of you.
	ACT_IDLE_ANGRY,			// FIXME: being used as an combat ready idle?  alternate idle animation in which the monster is clearly agitated. (loop)

	ACT_IDLE_RELAXED,
	ACT_IDLE_STIMULATED,
	ACT_IDLE_AGITATED,
	ACT_IDLE_STEALTH,
	ACT_IDLE_HURT,

	ACT_WALK_RELAXED,
	ACT_WALK_STIMULATED,
	ACT_WALK_AGITATED,
	ACT_WALK_STEALTH,

	ACT_RUN_RELAXED,
	ACT_RUN_STIMULATED,
	ACT_RUN_AGITATED,
	ACT_RUN_STEALTH,

	ACT_IDLE_AIM_RELAXED,
	ACT_IDLE_AIM_STIMULATED,
	ACT_IDLE_AIM_AGITATED,
	ACT_IDLE_AIM_STEALTH,

	ACT_WALK_AIM_RELAXED,
	ACT_WALK_AIM_STIMULATED,
	ACT_WALK_AIM_AGITATED,
	ACT_WALK_AIM_STEALTH,

	ACT_RUN_AIM_RELAXED,
	ACT_RUN_AIM_STIMULATED,
	ACT_RUN_AIM_AGITATED,
	ACT_RUN_AIM_STEALTH,

	ACT_CROUCHIDLE_STIMULATED,
	ACT_CROUCHIDLE_AIM_STIMULATED,
	ACT_CROUCHIDLE_AGITATED,

	ACT_WALK_HURT,			// limp  (loop)
	ACT_RUN_HURT,			// limp  (loop)
	ACT_SPECIAL_ATTACK1,	// very monster specific special attacks.
	ACT_SPECIAL_ATTACK2,
	ACT_COMBAT_IDLE,		// FIXME: unused?  agitated idle.
	ACT_WALK_SCARED,
	ACT_RUN_SCARED,
	ACT_VICTORY_DANCE,		// killed a player, do a victory dance.
	ACT_DIE_HEADSHOT,		// die, hit in head. 
	ACT_DIE_CHESTSHOT,		// die, hit in chest
	ACT_DIE_GUTSHOT,		// die, hit in gut
	ACT_DIE_BACKSHOT,		// die, hit in back
	ACT_FLINCH_HEAD,
	ACT_FLINCH_CHEST,
	ACT_FLINCH_STOMACH,
	ACT_FLINCH_LEFTARM,
	ACT_FLINCH_RIGHTARM,
	ACT_FLINCH_LEFTLEG,
	ACT_FLINCH_RIGHTLEG,
	ACT_FLINCH_PHYSICS,

	ACT_IDLE_ON_FIRE,		// ON FIRE animations
	ACT_WALK_ON_FIRE,
	ACT_RUN_ON_FIRE,

	ACT_RAPPEL_LOOP,		// Rappel down a rope!

	ACT_180_LEFT,			// 180 degree left turn
	ACT_180_RIGHT,

	ACT_90_LEFT,			// 90 degree turns
	ACT_90_RIGHT,

	ACT_STEP_LEFT,			// Single steps
	ACT_STEP_RIGHT,
	ACT_STEP_BACK,
	ACT_STEP_FORE,

	ACT_GESTURE_RANGE_ATTACK1,
	ACT_GESTURE_RANGE_ATTACK2,
	ACT_GESTURE_MELEE_ATTACK1,
	ACT_GESTURE_MELEE_ATTACK2,
	ACT_GESTURE_RANGE_ATTACK1_LOW,	// FIXME: not used yet, crouched versions of the range attack
	ACT_GESTURE_RANGE_ATTACK2_LOW,	// FIXME: not used yet, crouched versions of the range attack

	ACT_MELEE_ATTACK_SWING_GESTURE,

	ACT_GESTURE_SMALL_FLINCH,
	ACT_GESTURE_BIG_FLINCH,
	ACT_GESTURE_FLINCH_BLAST,			// Startled by an explosion
	ACT_GESTURE_FLINCH_BLAST_SHOTGUN,
	ACT_GESTURE_FLINCH_BLAST_DAMAGED,	// Damaged by an explosion
	ACT_GESTURE_FLINCH_BLAST_DAMAGED_SHOTGUN,
	ACT_GESTURE_FLINCH_HEAD,
	ACT_GESTURE_FLINCH_CHEST,
	ACT_GESTURE_FLINCH_STOMACH,
	ACT_GESTURE_FLINCH_LEFTARM,
	ACT_GESTURE_FLINCH_RIGHTARM,
	ACT_GESTURE_FLINCH_LEFTLEG,
	ACT_GESTURE_FLINCH_RIGHTLEG,

	ACT_GESTURE_TURN_LEFT,
	ACT_GESTURE_TURN_RIGHT,
	ACT_GESTURE_TURN_LEFT45,
	ACT_GESTURE_TURN_RIGHT45,
	ACT_GESTURE_TURN_LEFT90,
	ACT_GESTURE_TURN_RIGHT90,
	ACT_GESTURE_TURN_LEFT45_FLAT,
	ACT_GESTURE_TURN_RIGHT45_FLAT,
	ACT_GESTURE_TURN_LEFT90_FLAT,
	ACT_GESTURE_TURN_RIGHT90_FLAT,

	LAST_SHARED_ACTIVITY,
} Activity;