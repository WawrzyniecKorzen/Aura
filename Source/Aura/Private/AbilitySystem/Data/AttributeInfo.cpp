// Wawrzyniec Korzen based on Udemy course


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeinfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	//fail
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cant find Info for Attribute Tag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this));
	}
	return FAuraAttributeInfo();
}
