// Fill out your copyright notice in the Description page of Project Settings.

#include "SplitscreenManager.h"

// Sets default values
ASplitscreenWithGap::ASplitscreenWithGap()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASplitscreenWithGap::BeginPlay()
{
    ApplySplitscreenWithGap();
    Super::BeginPlay();
}

// Called every frame
void ASplitscreenWithGap::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASplitscreenWithGap::ApplySplitscreenWithGap()
{
    UGameViewportClient* Viewport = GetWorld()->GetGameViewport();
    Viewport->MaxSplitscreenPlayers = 2;

    FSplitscreenData ScreenLayout;

    float W = 1.0f;
    float H = 0.45f;
    float X = 0.0f;
    float Y1 = 0.0f;
    float Y2 = 1.0f - H;

    auto Screen1 = FPerPlayerSplitscreenData(W, H, X, Y1);
    auto Screen2 = FPerPlayerSplitscreenData(W, H, X, Y2);

    ScreenLayout.PlayerData.Add(Screen1);
    ScreenLayout.PlayerData.Add(Screen2);

    Viewport->SplitscreenInfo[ESplitScreenType::TwoPlayer_Horizontal] = ScreenLayout;
}