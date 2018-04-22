// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Ship_Forms1GameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShip_Forms1GameModeBase() {}
// Cross Module References
	SHIP_FORMS1_API UClass* Z_Construct_UClass_AShip_Forms1GameModeBase_NoRegister();
	SHIP_FORMS1_API UClass* Z_Construct_UClass_AShip_Forms1GameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Ship_Forms1();
// End Cross Module References
	void AShip_Forms1GameModeBase::StaticRegisterNativesAShip_Forms1GameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AShip_Forms1GameModeBase_NoRegister()
	{
		return AShip_Forms1GameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AShip_Forms1GameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_Ship_Forms1,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "Ship_Forms1GameModeBase.h" },
				{ "ModuleRelativePath", "Ship_Forms1GameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AShip_Forms1GameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AShip_Forms1GameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShip_Forms1GameModeBase, 2934683011);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShip_Forms1GameModeBase(Z_Construct_UClass_AShip_Forms1GameModeBase, &AShip_Forms1GameModeBase::StaticClass, TEXT("/Script/Ship_Forms1"), TEXT("AShip_Forms1GameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShip_Forms1GameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
