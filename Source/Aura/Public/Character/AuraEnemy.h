// Wawrzyniec Korzen based on Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	
	/*Enemy interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/*end Enemy interface */

	/*Combat interface*/
	virtual int32 GetPlayerLevel() override;
	/*end Combat interface */
	
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

protected:
	void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

private:

	
};
