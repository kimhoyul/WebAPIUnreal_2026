// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "http.h"
#include "RankingSubsystem.generated.h"

// 서버의 GameResult 모델과 매칭되는 언리얼에서 사용할 구조체
USTRUCT(BlueprintType)
struct FGameResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ranking")
	int32 Id = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ranking")
	int32 UserId;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ranking")
	FString UserName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ranking")
	FString UserEmail;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ranking")
	int32 Score = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ranking")
	FString Date;
};

// Add / Update / Delete 결과용 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActionSuccessSignature, bool, bSuccess);
// 전체 조회 결과용 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetRankingSignature, const TArray<FGameResult>&, RankingList);
// 단일 조회 결과용 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetSingleRankingSignature, bool, bSuccess, const FGameResult&, SingleResult);

/**
 * 
 */
UCLASS()
class URankingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public :
	// Add / Update / Delete 완료 이벤트
	UPROPERTY(BlueprintAssignable, Category = "Ranking/Event")
	FOnActionSuccessSignature OnActionCompleted;

	// Add / Update / Delete 완료 이벤트
	UPROPERTY(BlueprintAssignable, Category = "Ranking/Event")
	FOnGetRankingSignature OnGetRankingCompleted;

	// Add / Update / Delete 완료 이벤트
	UPROPERTY(BlueprintAssignable, Category = "Ranking/Event")
	FOnGetSingleRankingSignature OnGetSingleRankingCompleted;
};
