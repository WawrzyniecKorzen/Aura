// Wawrzyniec Korzen based on Udemy course


#include "UI/WidgetController/AuraWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UAuraWidgetController::SetWidgetControllerParams(FWidgetControllerParams WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}
