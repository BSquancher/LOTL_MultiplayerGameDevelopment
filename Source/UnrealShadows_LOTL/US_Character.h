// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "US_Character.generated.h"

UCLASS()
class UNREALSHADOWS_LOTL_API AUS_Character : public ACharacter
{
	GENERATED_BODY()

	/* NOTES: We declare pointer to the Input Mapping context and a pointer for each Input Action*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> SprintAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> InteractAction;
	
    
    /*Notes: We are declaring a Camera component and a Spring component that will create the camera system
         * VisibleAnywhere - indicates that this property is visible in all related windows of the UE Editor but cannot be edited
         * BluePrintReadOnly - indicates that this property can be read by Blueprints but not modified
         * Category - specifies the category of the property when displayed in the Blueprints Details panel
        */
    
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class USpringArmComponent> CameraBoom;
UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UCameraComponent> FollowCamera;

public:
	// Sets default values for this character's properties
	AUS_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*NOTES: Add a method for each of the interactions we defined before
	 */
	void Move(const struct FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void SprintStart(const FInputActionValue& Value);
	void SprintEnd(const FInputActionValue& Value);
	void Interact(const FInputActionValue& Value);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    /* NOTES: These two methods will let you acess the pointer components
     * FORCEINLINE macro forces the code to be inlined
     * This will give the code some performance benefits as we will avoid a function call when using this method*/
    
    FORCEINLINE USpringArmComponent* GetCameraBoom() const
    {return CameraBoom;}
    FORCEINLINE UCameraComponent* GetFollowCamera() const
    {return FollowCamera;}

};
