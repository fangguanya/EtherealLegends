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

#include "Gear/Magic/Spells/Cure.h"
#include "Gear/Magic/Spells/CureII.h"
#include "Gear/Magic/Spells/Regen.h"
#include "Gear/Magic/Spells/Refresh.h"
#include "Gear/Magic/Spells/Blizzard.h"
#include "Gear/Magic/Spells/Thunder.h"
#include "Gear/Magic/Spells/Fire.h"
#include "Gear/Magic/Spells/Berserk.h"
#include "Gear/Magic/Spells/Barrier.h"
#include "Gear/Magic/Spells/Haste.h"
#include "Gear/Magic/Spells/Dash.h"

#include "Gear/Weapons/OneHanded/IronSword.h"
#include "Gear/Weapons/OneHanded/Joyeuse.h"
#include "Gear/Weapons/OneHanded/Hauteclaire.h"
#include "Gear/Weapons/OneHanded/Excalibur.h"
#include "Gear/Weapons/OneHanded/BalloonSword.h"
#include "Gear/Weapons/OneHanded/BeamSaber.h"

#include "Gear/Weapons/OneHanded/Shields/Aegis.h"
#include "Gear/Weapons/OneHanded/Shields/DiablosDread.h"
#include "Gear/Weapons/OneHanded/Shields/SpartanShield.h"
#include "Gear/Weapons/OneHanded/Shields/WarAspis.h"

#include "Gear/Weapons/Ranged/ShortBow.h"
#include "Gear/Weapons/Ranged/EagleEye.h"
#include "Gear/Weapons/Ranged/EurytosBow.h"
#include "Gear/Weapons/Ranged/Annihilator.h"

#include "Gear/Weapons/Ranged/Ammo/DemonArrow.h"
#include "Gear/Weapons/Ranged/Ammo/FlameArrow.h"
#include "Gear/Weapons/Ranged/Ammo/IronArrow.h"
#include "Gear/Weapons/Ranged/Ammo/WoodenArrow.h"

#include "Gear/Weapons/TwoHanded/Marauder.h"
#include "Gear/Weapons/TwoHanded/Juggernaut.h"
#include "Gear/Weapons/TwoHanded/Claymore.h"
#include "Gear/Weapons/TwoHanded/Temperance.h"

#include "Gear/Weapons/Casting/MagicOrbs.h"

#include "Gear/Items/Consumable/Potion.h"
#include "Gear/Items/Consumable/HiPotion.h"
#include "Gear/Items/Consumable/Ether.h"
#include "Gear/Items/Consumable/HiEther.h"
#include "Gear/Items/Consumable/Reraise.h"
#include "Gear/Items/Consumable/Elixer.h"
#include "Gear/Items/Consumable/Adrenaline.h"
#include "Gear/Items/Consumable/SentinelBrew.h"

#include "Gear/Armor/Head/ClothCap.h"
#include "Gear/Armor/Head/AdamanHelm.h"
#include "Gear/Armor/Head/WarHelm.h"
#include "Gear/Armor/Head/ValhallaHelm.h"

#include "Gear/Armor/Cape/ClothCape.h"
#include "Gear/Armor/Cape/KnightsCape.h"
#include "Gear/Armor/Cape/ThiefsShroud.h"
#include "Gear/Armor/Cape/RestoreCloak.h"

#include "Gear/Armor/Body/ClothTunic.h"
#include "Gear/Armor/Body/AdamanCuirass.h"
#include "Gear/Armor/Body/WarCoat.h"
#include "Gear/Armor/Body/ValhallaBreastplate.h"

#include "Gear/Armor/Hand/ClothGloves.h"
#include "Gear/Armor/Hand/AdamanGauntlets.h"
#include "Gear/Armor/Hand/WarGloves.h"
#include "Gear/Armor/Hand/ValhallaGauntlets.h"

#include "Gear/Armor/Legs/ClothPants.h"
#include "Gear/Armor/Legs/AdamanCuisses.h"
#include "Gear/Armor/Legs/WarBrais.h"
#include "Gear/Armor/Legs/ValhallaFlanchard.h"

#include "Gear/Armor/Ring/SilverRing.h"
#include "Gear/Armor/Ring/DarksteelRing.h"
#include "Gear/Armor/Ring/ShadowRing.h"
#include "Gear/Armor/Ring/RestoreRing.h"

#include "Gear/Armor/Feet/ClothShoes.h"
#include "Gear/Armor/Feet/AdamanSabatons.h"
#include "Gear/Armor/Feet/WarBoots.h"
#include "Gear/Armor/Feet/ValhallaGreaves.h"

#include "EtherealGearManager.h"

// Sets default values
AEtherealGearManager::AEtherealGearManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Creates a Gear Item, when given a name
AEtherealGearMaster* AEtherealGearManager::CreateGear(EMasterGearList ItemToCreate)
{
	AEtherealGearMaster* Item = nullptr; // set a false item

	switch (ItemToCreate)  // This switch will run through and spawn a piece of Gear based on the name
	{
	case EMasterGearList::GL_None:
		// Do nothing, because the item is set to NONE!
		break;

	///////////////////////////////
	// MAGIC

	case EMasterGearList::GL_Cure:
		Item = GetWorld()->SpawnActor<ACure>();
		break;
	case EMasterGearList::GL_Cure2:
		Item = GetWorld()->SpawnActor<ACureII>();
		break;
	case EMasterGearList::GL_Raise:
		// Do nothing, because Raise does not yet exist
		break;
	case EMasterGearList::GL_Regen:
		Item = GetWorld()->SpawnActor<ARegen>();
		break;
	case EMasterGearList::GL_Refresh:
		Item = GetWorld()->SpawnActor<ARefresh>();
		break;
	case EMasterGearList::GL_Esuna:
		// Do nothing, because Esuna does not yet exist
		break;
	case EMasterGearList::GL_Comet:
		// Do nothing, because Comet does not yet exist
		break;
	case EMasterGearList::GL_Blizzard:
		Item = GetWorld()->SpawnActor<ABlizzard>();
		break;
	case EMasterGearList::GL_Thunder:
		Item = GetWorld()->SpawnActor<AThunder>();
		break;
	case EMasterGearList::GL_Fire:
		Item = GetWorld()->SpawnActor<AFire>();
		break;
	case EMasterGearList::GL_Poison:
		// Do nothing, because Poison does not yet exist
		break;
	case EMasterGearList::GL_Sleep:
		// Do nothing, because Sleep does not yet exist
		break;
	case EMasterGearList::GL_Berserk:
		Item = GetWorld()->SpawnActor<ABerserk>();
		break;
	case EMasterGearList::GL_Barrier:
		Item = GetWorld()->SpawnActor<ABarrier>();
		break;
	case EMasterGearList::GL_Haste:
		Item = GetWorld()->SpawnActor<AHaste>();
		break;
	case EMasterGearList::GL_Slow:
		// Do nothing, because Slow does not yet exist
		break;
	case EMasterGearList::GL_Counter:
		// Do nothing, because Counter does not yet exist
		break;
	case EMasterGearList::GL_Stun:
		// Do nothing, because Stun does not yet exist
		break;
	case EMasterGearList::GL_Dash:
		Item = GetWorld()->SpawnActor<ADash>();
		break;
	case EMasterGearList::GL_Gravity:
		// Do nothing, because Gravity does not yet exist
		break;

	///////////////////////////////
	// ONE-HANDED

	case EMasterGearList::GL_IronSword:
		Item = GetWorld()->SpawnActor<AIronSword>();
		break;
	case EMasterGearList::GL_Joyeuse:
		Item = GetWorld()->SpawnActor<AJoyeuse>();
		break;
	case EMasterGearList::GL_Hauteclaire:
		Item = GetWorld()->SpawnActor<AHauteclaire>();
		break;
	case EMasterGearList::GL_Excalibur:
		Item = GetWorld()->SpawnActor<AExcalibur>();
		break;
	case EMasterGearList::GL_BalloonSword:
		Item = GetWorld()->SpawnActor<ABalloonSword>();
		break;
	case EMasterGearList::GL_BeamSaber:
		Item = GetWorld()->SpawnActor<ABeamSaber>();
		break;

	///////////////////////////////
	// SHIELDS

	case EMasterGearList::GL_WarAspis:
		Item = GetWorld()->SpawnActor<AWarAspis>();
		break;
	case EMasterGearList::GL_SpartanShield:
		Item = GetWorld()->SpawnActor<ASpartanShield>();
		break;
	case EMasterGearList::GL_DiablosDread:
		Item = GetWorld()->SpawnActor<ADiablosDread>();
		break;
	case EMasterGearList::GL_Aegis:
		Item = GetWorld()->SpawnActor<AAegis>();
		break;

	///////////////////////////////
	// RANGED

	case EMasterGearList::GL_ShortBow:
		Item = GetWorld()->SpawnActor<AShortBow>();
		break;
	case EMasterGearList::GL_EagleEye:
		Item = GetWorld()->SpawnActor<AEagleEye>();
		break;
	case EMasterGearList::GL_EurytosBow:
		Item = GetWorld()->SpawnActor<AEurytosBow>();
		break;
	case EMasterGearList::GL_Annihilator:
		Item = GetWorld()->SpawnActor<AAnnihilator>();
		break;

	///////////////////////////////
	// AMMUNITION

	case EMasterGearList::GL_DemonArrow:
		Item = GetWorld()->SpawnActor<ADemonArrow>();
		break;
	case EMasterGearList::GL_FlameArrow:
		Item = GetWorld()->SpawnActor<AFlameArrow>();
		break;
	case EMasterGearList::GL_IronArrow:
		Item = GetWorld()->SpawnActor<AIronArrow>();
		break;
	case EMasterGearList::GL_WoodenArrow:
		Item = GetWorld()->SpawnActor<AWoodenArrow>();
		break;

	///////////////////////////////
	// TWO-HANDED

	case EMasterGearList::GL_Juggernaut:
		Item = GetWorld()->SpawnActor<AJuggernaut>();
		break;
	case EMasterGearList::GL_Claymore:
		Item = GetWorld()->SpawnActor<AClaymore>();
		break;
	case EMasterGearList::GL_Marauder:
		Item = GetWorld()->SpawnActor<AMarauder>();
		break;
	case EMasterGearList::GL_Temperance:
		Item = GetWorld()->SpawnActor<ATemperance>();
		break;

	///////////////////////////////
	// CASTING ORBS

	case EMasterGearList::GL_MagicOrbs:
		Item = GetWorld()->SpawnActor<AMagicOrbs>();
		break;

	///////////////////////////////
	// CONSUMABLE ITEMS

	case EMasterGearList::GL_Potion:
		Item = GetWorld()->SpawnActor<APotion>();
		break;
	case EMasterGearList::GL_HiPotion:
		Item = GetWorld()->SpawnActor<AHiPotion>();
		break;
	case EMasterGearList::GL_Ether:
		Item = GetWorld()->SpawnActor<AEther>();
		break;
	case EMasterGearList::GL_HiEther:
		Item = GetWorld()->SpawnActor<AHiEther>();
		break;
	case EMasterGearList::GL_Elixer:
		Item = GetWorld()->SpawnActor<AElixer>();
		break;
	case EMasterGearList::GL_Reraise:
		Item = GetWorld()->SpawnActor<AReraise>();
		break;
	case EMasterGearList::GL_Adrenaline:
		Item = GetWorld()->SpawnActor<AAdrenaline>();
		break;
	case EMasterGearList::GL_SentinelBrew:
		Item = GetWorld()->SpawnActor<ASentinelBrew>();
		break;

	///////////////////////////////
	// ARMOR - HEAD
	case EMasterGearList::GL_ClothCap:
		Item = GetWorld()->SpawnActor<AClothCap>();
		break;
	case EMasterGearList::GL_AdamanHelm:
		Item = GetWorld()->SpawnActor<AAdamanHelm>();
		break;
	case EMasterGearList::GL_WarHelm:
		Item = GetWorld()->SpawnActor<AWarHelm>();
		break;
	case EMasterGearList::GL_ValhallaHelm:
		Item = GetWorld()->SpawnActor<AValhallaHelm>();
		break;

	///////////////////////////////
	// ARMOR - CAPE
	case EMasterGearList::GL_ClothCape:
		Item = GetWorld()->SpawnActor<AClothCape>();
		break;
	case EMasterGearList::GL_KnightsCape:
		Item = GetWorld()->SpawnActor<AKnightsCape>();
		break;
	case EMasterGearList::GL_ThiefsShroud:
		Item = GetWorld()->SpawnActor<AThiefsShroud>();
		break;
	case EMasterGearList::GL_RestoreCloak:
		Item = GetWorld()->SpawnActor<ARestoreCloak>();
		break;

	///////////////////////////////
	// ARMOR - BODY
	case EMasterGearList::GL_ClothTunic:
		Item = GetWorld()->SpawnActor<AClothTunic>();
		break;
	case EMasterGearList::GL_AdamanCuirass:
		Item = GetWorld()->SpawnActor<AAdamanCuirass>();
		break;
	case EMasterGearList::GL_WarCoat:
		Item = GetWorld()->SpawnActor<AWarCoat>();
		break;
	case EMasterGearList::GL_ValhallaBreastplate:
		Item = GetWorld()->SpawnActor<AValhallaBreastplate>();
		break;

	//////////////////////////////
	// ARMOR - HANDS
	case EMasterGearList::GL_ClothGloves:
		Item = GetWorld()->SpawnActor<AClothGloves>();
		break;
	case EMasterGearList::GL_AdamanGauntlets:
		Item = GetWorld()->SpawnActor<AAdamanGauntlets>();
		break;
	case EMasterGearList::GL_WarGloves:
		Item = GetWorld()->SpawnActor<AWarGloves>();
		break;
	case EMasterGearList::GL_ValhallaGauntlets:
		Item = GetWorld()->SpawnActor<AValhallaGauntlets>();
		break;

	///////////////////////////////
	// ARMOR - LEGS
	case EMasterGearList::GL_ClothPants:
		Item = GetWorld()->SpawnActor<AClothPants>();
		break;
	case EMasterGearList::GL_AdamanCuisses:
		Item = GetWorld()->SpawnActor<AAdamanCuisses>();
		break;
	case EMasterGearList::GL_WarBrais:
		Item = GetWorld()->SpawnActor<AWarBrais>();
		break;
	case EMasterGearList::GL_ValhallaFlanchard:
		Item = GetWorld()->SpawnActor<AValhallaFlanchard>();
		break;

	///////////////////////////////
	// ARMOR - RING
	case EMasterGearList::GL_SilverRing:
		Item = GetWorld()->SpawnActor<ASilverRing>();
		break;
	case EMasterGearList::GL_DarksteelRing:
		Item = GetWorld()->SpawnActor<ADarksteelRing>();
		break;
	case EMasterGearList::GL_ShadowRing:
		Item = GetWorld()->SpawnActor<AShadowRing>();
		break;
	case EMasterGearList::GL_RestoreRing:
		Item = GetWorld()->SpawnActor<ARestoreRing>();
		break;

	///////////////////////////////
	// ARMOR - FEET
	case EMasterGearList::GL_ClothShoes:
		Item = GetWorld()->SpawnActor<AClothShoes>();
		break;
	case EMasterGearList::GL_AdamanSabatons:
		Item = GetWorld()->SpawnActor<AAdamanSabatons>();
		break;
	case EMasterGearList::GL_WarBoots:
		Item = GetWorld()->SpawnActor<AWarBoots>();
		break;
	case EMasterGearList::GL_ValhallaGreaves:
		Item = GetWorld()->SpawnActor<AValhallaGreaves>();
		break;

	}

	//////////////////////////////
	// END
	return Item;
}