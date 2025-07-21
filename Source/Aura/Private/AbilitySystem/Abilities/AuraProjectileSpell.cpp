// Wawrzyniec Korzen based on Udemy course


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "Actor/AuraProjectile.h"
#include "Interaction/CombatInterface.h"

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	const bool bIsServer = HasAuthority(&ActivationInfo);
	if (!bIsServer) return;

	//spawning projectile on server - client just returned

	FTransform SpawnTransform;

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (CombatInterface)
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		SpawnTransform.SetLocation(SocketLocation);

		// TO DO: set up the projectile rotation
		
		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>
		(
			ProjectileClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn
		);

		//TO DO: Give Tthe projectile Gameplay Effect Spec for causing Damage
		
		Projectile->FinishSpawning(SpawnTransform);
	}
	
	
}
