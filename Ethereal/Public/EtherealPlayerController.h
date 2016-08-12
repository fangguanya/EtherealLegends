// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once

#include "GameFramework/PlayerController.h"
#include "EtherealPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API AEtherealPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
		/** Called immediately after the game begins, from the Game Mode. */
		UFUNCTION(BlueprintCallable, Category = Default)
		void ClientPostLogin();
	
	
};
