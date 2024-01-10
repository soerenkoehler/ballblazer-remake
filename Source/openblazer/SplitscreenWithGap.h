// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/GameViewportClient.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"

#include "SplitscreenManager.generated.h"

UCLASS()
class OPENBLAZER_API ASplitscreenWithGap : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASplitscreenWithGap();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    virtual void ApplySplitscreenWithGap();
};
