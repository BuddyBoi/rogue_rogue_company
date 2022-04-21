#include <framework.h>
using namespace framework;

void lg( std::string msg )
{
	std::cout << "[ bd_debug ] " + msg << std::endl;
}

class Vector3
{
public:
	float x, y, z;
};

namespace variables
{
	const char* dwProcessName = "RogueCompany.exe";
	DWORD dwProcessId = NULL;
	uint64_t dwProcess_Base = NULL;
	HWND gameHWND = NULL;
	int actor_count = NULL;
	int ScreenHeight = 1080;
	int ScreenWidth = 1920;
	int ScreenLeft = NULL;
	int ScreenRight = NULL;
	int ScreenTop = NULL;
	int ScreenBottom = NULL;
	float ScreenCenterX = ScreenWidth / 2;
	float ScreenCenterY = ScreenHeight / 2;
	DWORD_PTR game_instance = NULL;
	DWORD_PTR u_world = NULL;
	DWORD_PTR local_player_pawn = NULL;
	DWORD_PTR local_player_array = NULL;
	DWORD_PTR local_player = NULL;
	DWORD_PTR local_player_root = NULL;
	DWORD_PTR local_player_controller = NULL;
	DWORD_PTR local_player_state = NULL;
	DWORD_PTR persistent_level = NULL;
	DWORD_PTR actors = NULL;
}
namespace offsets
{
	DWORD offset_g_names = 0x696c500; // https://rc.dumps.host/offsets GNames //ok
	DWORD offset_u_world = 0x6adb4f8; // https://rc.dumps.host/offsets GWorld //ok
	DWORD offset_camera_manager = 0x2b8; // APlayerController -> PlayerCameraManager //ok
	DWORD offset_camera_cache = 0x1aa0; //APlayerCameraManager -> CameraCachePrivate //ok
	DWORD offset_persistent_level = 0x30; //UWorld -> PersistentLevel //ok
	DWORD offset_game_instance = 0x188; //UWorld -> OwningGameInstance //ok
	DWORD offset_local_players_array = 0x38; //UGameInstance -> LocalPlayers //ok
	DWORD offset_player_controller = 0x30; //UPlayer -> PlayerController //ok
	DWORD offset_apawn = 0x2a0;  //APlayerController -> AcknowledgedPawn //ok
	DWORD offset_root_component = 0x130; //AActor -> RootComponent //ok
	DWORD offset_actor_array = 0x98; //UNetConnection -> OwningActor //ok
	DWORD offset_actor_count = 0xa0; //UNetConnection -> MaxPacket //ok
	DWORD offset_player_state = 0x240; //APawn -> PlayerState //ok
	DWORD offset_actor_mesh = 0x280; //ACharacter -> Mesh //ok
	DWORD offset_relative_location = 0x11c; //USceneComponent -> RelativeLocation //ok
	DWORD offset_health = 0x538; //AKSCharacterFoundation -> Health //ok
	DWORD offset_max_health = 0x282c; //AKSCharacter -> CachedMaxHealth //ok
	DWORD offset_player_name = 0x300; // APlayerState -> PlayerNamePrivate //ok
	DWORD BaseAccuracy = 0x68c; // UKSWeaponAsset -> BaseAccuracy //ok
	DWORD bDowned = 0x2859; // AKSCharacter -> bDowned //ok
	DWORD offset_bKickbackEnabled = 0xb18; // AKSPlayerController -> bKickbackEnabled //ok
	DWORD bInRagdoll = 0x2e80; // AKSCharacter -> bInRagdoll
	DWORD bCanMoveWhileRevivingOther = 0x2a68; // AKSCharacter -> bCanMoveWhileRevivingOther //ok
	DWORD ping = 0x228; // APlayerState -> Ping //ok
	DWORD r_Team = 0x3a8; // AKSPlayerState -> r_Team //ok
	DWORD r_TeamNum = 0x220; // AKSTeamState -> r_TeamNum //ok
	DWORD EliminatedState = 0x458; // AKSPlayerState -> EliminatedState //ok
	DWORD TimeDilation = 0x2e8; // AWorldSettings -> TimeDilation //ok
	DWORD ActiveWeaponComponent = 0x22e0; // AKSCharacter -> ActiveWeaponComponent[0xb] //ok
	DWORD WeaponAsset = 0x138; // UKSWeaponComponent -> WeaponAsset //ok
	DWORD bUnlimitedAmmo = 0x3d8; // UKSWeaponAsset -> bUnlimitedAmmo //ok
	DWORD MaxLungeDistance = 0x9a4; //UKSWeaponAsset_Melee -> MaxLungeDistance //ok
	DWORD MeleeSphereRadius = 0x984; //UKSWeaponAsset_Melee -> MeleeSphereRadius //ok
	DWORD bRevealed = 0x12fc; //AKSCharacterBase -> bRevealed //ok
	DWORD bForceSilhouette = 0x1331; //AKSCharacterBase -> bForceSilhouette
	DWORD bIsSpawnImmune = 0x1518; //AKSCharacterBase -> bIsSpawnImmune //ok
	DWORD bIgnoreCollisionWithTeammates = 0x4ed; //AKSCharacterFoundation -> bIgnoreCollisionWithTeammates //ok
	DWORD CurrentOverheal = 0xd90; //AKSCharacterBase -> CurrentOverheal //ok
	DWORD offset_last_submit_time = 0x2ac; // AServerStatReplicator -> NumRelevantDeletedActors //ok
	DWORD offset_last_render_time = 0x2b4; // AServerStatReplicator -> NumReplicatedActors //ok
	DWORD offset_actor_id = 0x18; // actor id //ok
	DWORD offset_component_to_world = 0x1c0; // component to world //ok
	DWORD offset_bone_array = 0x478; // UStaticMeshComponent -> StaticMesh //ok
	DWORD CurrentQuickMeleeWeapon = 0x2230; //AKSCharacter -> CurrentQuickMeleeWeapon //ok
	DWORD MeleeWeaponAsset = 0x868; //AKSWeapon_Melee -> MeleeWeaponAsset //ok
	DWORD BaseEyeHeight = 0x22c; //APawn -> BaseEyeHeight //ok
	DWORD AmmoInClip = 0x4a4; //AKSWeapon -> AmmoInClip //ok
	DWORD ClipSize = 0x4a8; //AKSWeapon -> ClipSize //ok
	DWORD DefaultFOV = 0x238; //APlayerCameraManager -> DefaultFOV //ok
	DWORD NoSpread = 0x68c; //UKSWeaponAsset -> BaseAccuracy //ok
	DWORD firemodetype = 0x368; //UKSWeaponAsset -> FireModeType //ok
	DWORD CurrentRevealColor = 0x1300; //AKSCharacterBase -> CurrentRevealColor //ok
	DWORD CharacterMovement = 0x288; //ACharacter -> CharacterMovement //ok
	DWORD KSCharacterOwner = 0x868; //UKSCharacterMovementComponent -> KSCharacterOwner //ok
	DWORD SpawnImmuneOutlineColorEnemy = 0x1318; //AKSCharacterBase -> SpawnImmuneOutlineColorEnemy //ok
	DWORD PreFireTime = 0x378; //UKSWeaponAsset -> PreFireTime //ok
	DWORD RoundsPerBurst = 0x36c; //UKSWeaponAsset -> RoundsPerBurst //ok
	DWORD AimDownSightsFov = 0x5c0; //UKSWeaponAsset -> AimDownSightsFov //ok
	DWORD PostReloadTime = 0x3c0; //UKSWeaponAsset -> PostReloadTime //ok
	DWORD PreReloadTime = 0x3bc; //UKSWeaponAsset -> PreReloadTime //ok
	DWORD trollnoreload = 0x3b0; //UKSWeaponAsset -> bCanEverReload //ok
	DWORD trollnofire = 0x330; //UKSWeaponAsset -> bCanEverFire //ok
	DWORD aimovershoulder = 0x5ac; //UKSWeaponAsset -> bCanEverAimOverShoulder //ok
	DWORD aimdownsights = 0x5b4; //UKSWeaponAsset -> bCanEverAimDownSights //ok
	DWORD ReloadType = 0x3b8; //UKSWeaponAsset -> ReloadType //ok
	DWORD DamageCategory = 0x40; //UKSDamageTypeBase -> DamageCategory //ok
	DWORD ReticleType = 0x3e9; //UKSWeaponAsset -> ReticleType //ok
	DWORD WeaponEquipType = 0x280; //UKSWeaponAsset -> WeaponEquipType //ok
	DWORD WalkSpeedModifier = 0x280; //UKSWeaponAsset -> WeaponEquipType //ok
	DWORD ClipSize2 = 0x3b4; //UKSWeaponAsset -> ClipSize //ok
	DWORD HeadDamageAmount = 0x534; //UKSWeaponAsset -> HeadDamageAmount //ok
	DWORD DamageAmount = 0x538; //UKSWeaponAsset -> DamageAmount //ok
	DWORD LimbDamageAmount = 0x53c; //UKSWeaponAsset -> LimbDamageAmount //ok
	DWORD BurstShotIndex = 0x45c; //AKSWeapon -> BurstShotIndex //ok
	DWORD PostFireTime = 0x384; //UKSWeaponAsset -> PostFireTime //ok
	DWORD AltPostFireTime = 0x388; //UKSWeaponAsset -> AltPostFireTime //ok
	DWORD PostFireForgivenessTime = 0x38c; //UKSWeaponAsset -> PostFireForgivenessTime //ok
	DWORD InitialPostFireTime = 0x39c; //UKSWeaponAsset -> InitialPostFireTime //ok
	DWORD FinalPostFireTime = 0x3a0; //UKSWeaponAsset -> FinalPostFireTime //ok
	DWORD PostFireChargeTime = 0x3a4; //UKSWeaponAsset -> PostFireChargeTime //ok
	DWORD PostFireDecayTime = 0x3a8; //UKSWeaponAsset -> PostFireDecayTime //ok
	DWORD PostFireDecayDelay = 0x3ac; //UKSWeaponAsset -> PostFireDecayDelay //ok
	DWORD AmmoType = 0x3d1; //UKSWeaponAsset -> AmmoType //ok
	DWORD ReloadCooldownTime = 0x3c4; //UKSWeaponAsset -> ReloadCooldownTime //ok
	DWORD FirstShotPreReloadTime = 0x3cc; //UKSWeaponAsset -> FirstShotPreReloadTime //ok
	DWORD DamageTypeClass = 0x578; //UKSWeaponAsset -> DamageTypeClass //ok
}
namespace game
{
	std::string window_title = "Rogue Company  ";
	std::string window_class = "UnrealWindow";

	template<class T>
	class TArray
	{
	public:
		int Length() const
		{
			return m_nCount;
		}
		bool IsValid() const
		{
			if ( m_nCount > m_nMax )
				return false;
			if ( !m_Data )
				return false;
			return true;
		}
		uint64_t GetAddress() const
		{
			return m_Data;
		}
		T GetById( int i )
		{
			return driver::read<T>( m_Data + i * 8 );
		}
	protected:
		uint64_t m_Data;
		uint32_t m_nCount;
		uint32_t m_nMax;
	};
	void move_to( float x, float y )
	{
		float smooth = 1.0f;

		float center_x = 1920 / 2;
		float center_y = 1080 / 2;
		float target_x = 0.f;
		float target_y = 0.f;
		if ( x != 0.f )
		{
			if ( x > center_x )
			{
				target_x = -(center_x - x);
				target_x /= smooth;
				if ( target_x + center_x > center_x * 2.f ) target_x = 0.f;
			}
			if ( x < center_x )
			{
				target_x = x - center_x;
				target_x /= smooth;
				if ( target_x + center_x < 0.f ) target_x = 0.f;
			}
		}
		if ( y != 0.f )
		{
			if ( y > center_y )
			{
				target_y = -(center_y - y);
				target_y /= smooth;
				if ( target_y + center_y > center_y * 2.f ) target_y = 0.f;
			}
			if ( y < center_y )
			{
				target_y = y - center_y;
				target_y /= smooth;
				if ( target_y + center_y < 0.f ) target_y = 0.f;
			}
		}
		mouse_event( MOUSEEVENTF_MOVE, static_cast<DWORD>(target_x), static_cast<DWORD>(target_y), 0, 0 );
	}
	auto characterbase()
	{
		auto m_Charatermovement = driver::read<uint64_t>( variables::local_player_pawn + offsets::CharacterMovement );
		return driver::read<uint64_t>( m_Charatermovement + offsets::KSCharacterOwner );
	}
	auto weaponasset()
	{
		auto ActiveWeapon = driver::read<uint64_t>( variables::local_player_pawn + offsets::ActiveWeaponComponent );
		return driver::read<uint64_t>( ActiveWeapon + offsets::WeaponAsset );
	}
	auto MeleeWeaponAsset()
	{
		uint64_t CurrentQuickMeleeWeapon = driver::read<uint64_t>( variables::local_player_pawn + offsets::CurrentQuickMeleeWeapon );
		return driver::read<uint64_t>( CurrentQuickMeleeWeapon + offsets::MeleeWeaponAsset );
	}

	typedef struct _EntityList
	{
		uintptr_t actor_pawn;
		uintptr_t actor_mesh;
		uintptr_t actor_state;
		float actor_health_max;
		float actor_health;
		int actor_id;

	}EntityList;
	std::vector<EntityList> entityList;

	bool b_setup()
	{
		while ( !FindWindowA( window_class.c_str(), window_title.c_str() ) )
		{
			Sleep( 5000 );
			lg( "waiting for g" );
		}

		HWND t_hwnd = LI_FN( FindWindowA ).forwarded_safe_cached()(window_class.c_str(), window_title.c_str());
		if ( !t_hwnd )
			return false;

		DWORD temp_pid = 0;
		LI_FN( GetWindowThreadProcessId ).forwarded_safe_cached()(t_hwnd, &temp_pid);
		CloseWindow( t_hwnd );
		if ( !temp_pid )
			return false;

		driver::process_id = temp_pid;
		variables::dwProcess_Base = driver::get_base_address( driver::process_id );
		if ( !variables::dwProcess_Base )
		{
			std::cout << "can't find base address" << std::endl;
			return false;
		}

		return true;
	}

	void no_spread()
	{
		//force accuracy
		float current_float = driver::read<float>( weaponasset() + offsets::NoSpread );
		if ( current_float > 100.0f || current_float < 0.0f )
			return;

		if(current_float < 100.0f && current_float >= 0.0f )
			driver::write<float>( weaponasset() + offsets::NoSpread, 100.0f );
	}

	void cheat_loop()
	{
		while ( LI_FN(FindWindowA).forwarded_safe_cached()(window_class.c_str(), window_title.c_str()) )
		{
			std::this_thread::sleep_for( std::chrono::milliseconds( 250 ) );

			lg( "in loop" );

			//update cache
			std::vector<EntityList> tmpList;

			//get main variables
			variables::u_world = driver::read<DWORD_PTR>( variables::dwProcess_Base + offsets::offset_u_world );
			if ( !variables::u_world )
				continue;

			variables::game_instance = driver::read<DWORD_PTR>( variables::u_world + offsets::offset_game_instance );
			if ( !variables::game_instance )
				continue;

			variables::persistent_level = driver::read<DWORD_PTR>( variables::u_world + offsets::offset_persistent_level );
			if ( !variables::persistent_level )
				continue;

			variables::actors = driver::read<DWORD_PTR>( variables::persistent_level + offsets::offset_actor_array );
			if ( !variables::actors )
				continue;

			variables::actor_count = driver::read<int>( variables::persistent_level + offsets::offset_actor_count );
			if ( !variables::actor_count )
				continue;

			variables::local_player_array = driver::read<DWORD_PTR>( variables::game_instance + offsets::offset_local_players_array );
			if ( !variables::local_player_array )
				continue;

			variables::local_player = driver::read<DWORD_PTR>( variables::local_player_array );
			if ( !variables::local_player )
				continue;

			variables::local_player_controller = driver::read<DWORD_PTR>( variables::local_player + offsets::offset_player_controller );
			if ( !variables::local_player_controller )
				continue;

			variables::local_player_pawn = driver::read<DWORD_PTR>( variables::local_player_controller + offsets::offset_apawn );
			if ( !variables::local_player_pawn )
				continue;

			variables::local_player_root = driver::read<DWORD_PTR>( variables::local_player_pawn + offsets::offset_root_component );
			if ( !variables::local_player_root )
				continue;

			variables::local_player_state = driver::read<DWORD_PTR>( variables::local_player_pawn + offsets::offset_player_state );
			if ( !variables::local_player_state )
				continue;

			//get local player info
			float local_health = driver::read<float>( variables::local_player_pawn + offsets::offset_health );
			float local_health_max = driver::read<float>( variables::local_player_pawn + offsets::offset_max_health );

			if ( local_health < 1 )
			{
				lg( "you are not alive" );
				continue;
			}

			lg( "player health : " + std::to_string( local_health ) );
			lg( "player health max : " + std::to_string( local_health_max ) );

			no_spread();
			
			//update entitylist
			for ( int index = 0; index < variables::actor_count; ++index )
			{
				auto actor_pawn = driver::read<DWORD_PTR>( variables::actors + index * 0x8 );
				if ( actor_pawn == 0x00 )
					continue;

				//skip localplayer
				if ( actor_pawn == variables::local_player_pawn )
					continue;

				auto actor_id = driver::read<int>( actor_pawn + offsets::offset_actor_id );
				auto actor_state = driver::read<DWORD_PTR>( actor_pawn + offsets::offset_player_state );
				auto actor_mesh = driver::read<DWORD_PTR>( actor_pawn + offsets::offset_actor_mesh );
				EntityList Entity{ };
				Entity.actor_pawn = actor_pawn;
				Entity.actor_id = actor_id;

				if ( actor_pawn != NULL || actor_id != NULL || actor_state != NULL || actor_mesh != NULL )
				{
					EntityList Entity{ };
					Entity.actor_pawn = actor_pawn;
					Entity.actor_id = actor_id;
					Entity.actor_state = actor_state;
					Entity.actor_mesh = actor_mesh;

					Entity.actor_health = driver::read<float>( Entity.actor_pawn + offsets::offset_health );
					Entity.actor_health_max = driver::read<float>( Entity.actor_pawn + offsets::offset_max_health );

					if ( Entity.actor_health > 1.0f && Entity.actor_health <= 100.0f )
					{
						int current_silhouette = driver::read<bool>( Entity.actor_pawn + offsets::bForceSilhouette );
						int current_revealed = driver::read<bool>( Entity.actor_pawn + offsets::bRevealed );

						if( !current_silhouette )
							driver::write<int>( Entity.actor_pawn + offsets::bForceSilhouette, true );

						if(!current_revealed )
							driver::write<int>( Entity.actor_pawn + offsets::bRevealed, true );
					}

					tmpList.push_back( Entity );
				}
			}
			entityList = tmpList;

			//localplayer features
			no_spread();
		}
		lg( "game over?" );
	}
}

//test login
int main()
{
	SetConsoleTitleA( framework::util::get_random_string( 128 ).c_str() );

	std::string username = "";
	std::string password = "";

	std::cout << "username:" << std::endl;
	std::cin >> username;
	std::cout << "password:" << std::endl;
	std::cin >> password;

	if ( !framework::api::auth( username, password ) )
	{
		lg( "auth sad :(" );
		Sleep( 3000 );
		return 0;
	}

	lg( "auth happy :)" );

	//start driver
	if ( driver::load() != 0 )
	{
		lg( "driver too tired to wake up :(" );
		Sleep( 1000 );
		return 0;
	}
	lg( "driver happy" );

	//ping driver
	driver::ping( 1 );
	lg( "driver awake" );
	Sleep( 1000 );

	if ( !game::b_setup() )
		lg( "game setup failed" );
	else
		game::cheat_loop();

	//end driver
	lg( "putting driver down" );
	driver::unload();
	lg( "driver euthanized" );
	Sleep( 3500 );
	return 1337;
}