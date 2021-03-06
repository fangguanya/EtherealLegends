// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "WarAspis.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AWarAspis::AWarAspis(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/VFX/sphere_skeletal.sphere_skeletal'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/Elemental/Environment/Throne_Warspoils/Mesh/WarAspis.WarAspis'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> OffhandMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_WarAspis.WeaponIcon_WarAspis'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_WarAspis-small.WeaponIcon_WarAspis-small'"));


	// Set Default Objects

	Name = EMasterGearList::GL_WarAspis;
	NameText = LOCTEXT("WarAspisName", "War Aspis");
	Type = EMasterGearTypes::GT_Shield;
	TypeText = LOCTEXT("WarAspisType", "Shield");
	Description = "A basic shield, solid and battle-tested. Standard issue for Ethereal Knights.";
	Price = 5000;
	MPCost = 0.0f;
	ATK = 5.0f;
	DEF = 5.0f;
	SPD = 0.0f;
	HP = 100.0f;
	MP = 50.0f;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	SK_WeaponSkeletalMesh = SkeletalMeshObject.Object;
	SM_WeaponStaticMesh = StaticMeshObject.Object;
	SM_WeaponOffhandMesh = StaticMeshObject.Object;

	// Set Mesh
	WeaponSkeletalMesh->SetSkeletalMesh(SK_WeaponSkeletalMesh);
	WeaponSkeletalMesh->SetHiddenInGame(true);
	WeaponStaticMesh->SetStaticMesh(SM_WeaponStaticMesh);
	WeaponStaticMesh->SetRelativeLocation(FVector(0, 0, 10));
	WeaponStaticMesh->SetWorldScale3D(FVector(2, 2, 2)); // Scale correction
	WeaponOffhandMesh->SetStaticMesh(SM_WeaponOffhandMesh);
	WeaponOffhandMesh->SetHiddenInGame(true);

	//WeaponStaticMesh->SetVisibility(true);
	//SwordCollider->SetBoxExtent(FVector(5.0f, 5.0f, 25.0f));
	//SwordCollider->SetRelativeLocation(FVector(0.0f, 0.0f, 5.0f));
}

// Called when the game starts or when spawned
void AWarAspis::BeginPlay()
{
	Super::BeginPlay();

	// Bind this function to the event dispatcher for Bind Gear
	OnBindGear.AddDynamic(this, &AWarAspis::BindWeapon);
}

// Custom code when binding
void AWarAspis::BindWeapon()
{
	// If this weapon was bound while IsShown is true, set the weapon visible
	if (IsShown)
	{
		ShowWeapon(false, true, false);
	}
}

#undef LOCTEXT_NAMESPACE
