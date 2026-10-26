// Fill out your copyright notice in the Description page of Project Settings.


#include "RankingSubsystem.h" 
#include "Dom/JsonObject.h"					// JSON 객체를 사용하기 위한 헤더
#include "Dom/JsonValue.h"					// JSON 배열 값을 사용하기 위한 헤더
#include "Serialization/JsonReader.h"		// JSON 문자열을 읽기 위한 헤더
#include "Serialization/JsonSerializer.h"	// JSON 직렬화와 역직렬화 를 위한 헤더
#include "Serialization/JsonWriter.h"		// JSON 문자열을 만들기 위한 헤더

// JSON 객체 하나를 FGameResult 구조체로 변환하는 내부용 함수
static void JsonObjectToGameResult(const TSharedPtr<FJsonObject>& JsonObject, OUT FGameResult& OutResult)
{
	if (!JsonObject.IsValid()) // JSON 객체가 유효하지 않으면 처리 안함
		return;

	// JSON 의 숫자 값은 Double로 읽히기 때문에 만든 임시 변환 변수
	double IdValue = 0.0;

	// JSON 문자열에서 Key 값이 "id" 이거나 "Id" 인 애를 찾으면 IdValue 변수에 해당 Value 를 넣어줘
	if (JsonObject->TryGetNumberField(TEXT("id"), IdValue) || JsonObject->TryGetNumberField(TEXT("Id"), IdValue))
		OutResult.Id = static_cast<int32>(IdValue);


}

