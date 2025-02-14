#include "stdafx.h"
#include "Parts_09.h"

void Parts_09()
{
	Enumeration();
	// Union();
	// Structure();
}

void Structure()
{
	printf("Test 구조체 크기 : %lld\n", sizeof(struct Test));

	Player player1;
	player1.id = 1;
	player1.level = 1;
	player1.hp = 10;
	player1.atk = 2;

	// 멤버 이니셜라이저
	/*
	멤버를 순서대로 초기화 하는것이다.
	*/
	Player player2 = { 2, 2, 25, 1 };

	printf("===== 각 플레이어 초기 정보 =====\n");
	PrintPlayerInfo(player1);
	PrintPlayerInfo(player2);

	Player players[] =
	{
		player1,
		player2,
		{ 3, 2, 15, 2 },
		{ 4, 1, 15, 1 }
	};

	const int numPlayers = sizeof(players) / sizeof(players[0]);

	printf("\n===== 각 플레이어 초기 정보(배열) =====\n");
	for (int i = 0; i < numPlayers; ++i)
		PrintPlayerInfo(players[i]);

	printf("\n");

	system("pause");
	system("cls");

	int sel;

	while (true)
	{
		printf("===== LevelUp 프로그램 =====\n");
		printf("\nLevelUp 대상 플레이어 선택 (1 ~ 4) : ");
		scanf("%d", &sel);

		if (sel > 0 && sel <= 4)
		{
			players[sel - 1] = PlayerLevelUp(players[sel - 1]);

			printf("\n===== LevelUp 결과 =====\n");
			for (int i = 0; i < numPlayers; ++i)
				PrintPlayerInfo(players[i]);

			printf("\n");

			system("pause");
			system("cls");
		}
		else if (sel == 0)
			break;
		else
		{
			printf("\n===== LevelUp 결과 =====\n");
			printf("\n잘못된 플레이어 id를 입력하셨습니다. 정확한 플레이어 id(1 ~ 4)를 입력해주세요.\n\n");

			system("pause");
			system("cls");
		}
	}
}

void PrintPlayerInfo(Player player)
{
	printf("플레이어 %d 정보 [ Level : %d, HP : %d, ATK : %d ]\n", player.id, player.level, player.hp, player.atk);
}

Player PlayerLevelUp(Player up)
{
	up.level++;
	up.hp += 10;
	up.atk++;
	return up;
}

void Union()
{
	printf("공용체 크기 : %zd\n", sizeof(Data));

	Data data = { 0 };
	data.intNum = 123456789;

	printf("\n===== Int 할당 결과 =====\n");
	printf("Int : %d\n", data.intNum);
	printf("Float : %f\n", data.fltNum);
	printf("Double : %lf\n", data.dblNum);

	data.fltNum = 3.14f;

	printf("\n===== Float 할당 결과 =====\n");
	printf("Int : %d\n", data.intNum);
	printf("Float : %f\n", data.fltNum);
	printf("Double : %lf\n", data.dblNum);

	data.dblNum = 3.141592;

	printf("\n===== Double 할당 결과 =====\n");
	printf("Int : %d\n", data.intNum);
	printf("Float : %f\n", data.fltNum);
	printf("Double : %lf\n", data.dblNum);

	/*
	실행 결과를 보면 싹다 대입한 값을 제외하면 전부 똥값이 들어간걸 볼수가 있다
	이런걸 보면 솔직히 게임 만들면서 한번도 안쓸만한 극한의 최적화를 위한것이기에
	임베디드를 할껄 아니라면 자신이 1980년대 게임을 개발하는 슈퍼마리오를 개발할게 아니라면
	영원히? 그냥 살면서 왠만하면 쓸일이 없을것이다. 그래도 혹시 모르니 진짜 호오오오오옥시 모르니 알아두자
	*/
}

void Enumeration()
{
	Status status = STATUS_NONE;
	Motion statis = MOTION_NONE;
	/*
	이렇게 같은 이름으로 선언을 하면
	지금 무슨 문제가 발생했느냐
	재정의 문제가 발생을 했는데

	이럴때 뒤나 앞에 접두나 접미를 붙히면 해결된다.
	*/

	printf("===== 열거형 상수 =====\n");
	printf("Gold : %d\n", ITEM_GOLD);
	printf("Weapon : %d\n", ITEM_WEAPON);
	printf("Armor : %d\n", ITEM_ARMOR);

	ItemType itemType = ITEM_WEAPON;

	printf("===== 열거형 상수 =====\n");
	printf("ItemType is Gold : %s\n", itemType == ITEM_GOLD ? "True" : "False");
	printf("ItemType is Weapon : %s\n", itemType == ITEM_WEAPON ? "True" : "False");
	printf("ItemType is Armor : %s\n", itemType == ITEM_ARMOR ? "True" : "False");

	system("pause");
	system("cls");

	if (itemType == ITEM_WEAPON)
	{
		WeaponType weaponType = WEAPON_NONE;

		do
		{
			system("cls");
			printf("===== 무기 교체 프로그램 =====\n\n");
			printf("1. 검 2. 활 3. 총 4. 나가기\n\n메뉴 입력 : ");
			scanf("%d", &weaponType);
			--weaponType;
			printf("\n");

			switch (weaponType)
			{
			case WEAPON_SWORD:
				printf("현재 무기 : 검");
				break;
			case WEAPON_BOW:
				printf("현재 무기 : 활");
				break;
			case WEAPON_GUN:
				printf("현재 무기 : 총");
				break;
			case WEAPON_MAX_VALUE:
				printf("프로그램을 종료합니다.");
				break;
			default:
				printf("잘못된 숫자를 입력하셨습니다. 다시 입력해주세요.");
				break;
			}

			printf("\n\n");
			system("pause");
		} while (weaponType != WEAPON_MAX_VALUE);
	}

}

/*
레벨1 올리면
체력 10, 공격력 1 오르고

레벨업 대상 선택
그리고 레벨업 결과 출력

반복문 구조 0되면 프로그램 종료

===== LevelUp 프로그램 =====

LevelUp 대상 플레이어 선택 (1 ~ 4) : 1

===== LevelUp 결과 =====
플레이어 1 정보 [ Level : 6, HP : 60, ATK : 7 ]
*/

/*

	int selWP;

	if (itemType == ITEM_WEAPON)
	{
		bool run = true;
		WeaponType weaponType = WEAPON_NONE;
		while (run)
		{
			system("pause");
			system("cls");
			printf("===== 무기 교체 프로그램 =====\n");
			printf("\n1. 검 2. 활 3. 총 4. 나가기\n");
			printf("\n메뉴입력 : ");
			scanf("%d", &selWP);
			switch (selWP)
			{
			case 1:
			{
				printf("\n검을 장착했습니다.\n\n");
			}break;
			case 2:
			{
				printf("\n활을 장착했습니다.\n\n");
			}break;
			case 3:
			{
				printf("\n총을 장착했습니다.\n\n");
			}break;
			case 4:
			{
				printf("\n프로그램을 종료합니다.\n\n");
				run = false;
				system("pause");
			}break;
			default:
			{
				printf("\n잘못된 숫자를 입력하였습니다.\n\n");
				system("pause"), system("cls");
			}break;
			}
		}
	}

	*/