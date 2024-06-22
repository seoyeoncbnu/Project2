#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> //콘솔창(getch)
#include <windows.h> //Sleep()

void boundaryShow();
void SetColor(int color);
void LateShow();
void choiceShow();
void chooseFortune();
void BackChoose();
void Todayfortune();
void RandomNum();
void Warningtarot();
void FortuneList();

void boundaryShow() {
	for (int i = 0; i < 35; i++)
		printf("*");
	printf("\n");
}

void SetColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void LateShow() {
	fflush(stdout);
	Sleep(2000); //2초 늦게 출력
	printf("\n");
}

void choiceShow() {
	printf("      ~ Choose your Fortune ~\n\n");
	boundaryShow();
	printf("\n\t1. 오늘의 행운지수\n\t2. 타로카드 뽑기\n\t3. 목록보기\n\t4. 나가기\n\n");
	boundaryShow();
	printf(">> ");
}

void BackChoose() {
	printf("뒤로가려면 'b'를 눌러주세요...");
	while (1) {
		char back = getch();
		if (back == 'b' || back == 'B') {
			break;
		}
	}
	system("cls");
	chooseFortune(); //b를 통해 선택지로 다시 이동
}

void Todayfortune() {
	// 난수 생성을 위한 시드 설정
	srand(time(NULL));

	//0부터 5까지의 난수 생성 (별의 개수)
	int numStars = rand() % 6;

	printf("      ~ 오늘의 ");
	SetColor(10);
	printf("행운지수");
	SetColor(7);
	printf("는? ~\n\n");
	boundaryShow();
	printf("\n\t오늘의 행운력: ");

	fflush(stdout);
	Sleep(2000);

	//총 5개의 자리에서 별의 개수만큼 왼쪽 정렬하여 출력
	for (int i = 0; i < 5; i++) {
		if (i < numStars) {
			printf("★");
		}
		else {
			printf("☆");
		}
	}

	//1부터 50까지의 난수 생성
	int luckyNumber = (rand() % 50) + 1;
	printf("\n\t행운의 번호: ");
	fflush(stdout);
	Sleep(2000);
	printf("%d\n\n", luckyNumber);
	boundaryShow();

	printf("\n해설:");
	LateShow();

	//별의 개수에 따라 메시지 출력
	switch (numStars) {
	case 0:
		printf("오늘 하루 조심하세요. 행운을 빕니다!\n");
		break;
	case 1:
		printf("예상한 결과가 나오지 않을 수 있습니다. 너무 무리하지 마세요.\n");
		break;
	case 2:
		printf("다소 불안한 하루가 될 수 있습니다. 작은 실수에도 주의하세요.\n");
		break;
	case 3:
		printf("평범한 하루지만, 다소 평화로운 날이 될 것입니다.\n");
		break;
	case 4:
		printf("행운의 날입니다! 하고 싶었던 일을 적극적으로 해보세요!\n");
		break;
	case 5:
		printf("축하합니다! 오늘의 행운아는 나야 나! 자신감을 가지고 적극적으로 활동해보세요!\n");
		break;
	}
	printf("\n");
	BackChoose();
	return 0;
}

void chooseFortune() {
	int whichFortune;
	char input;
	while (1) {
		choiceShow();
		//숫자가 아닌 경우
		if (scanf("%d", &whichFortune) != 1) {
			printf("\nERROR: 숫자를 입력해주세요.\n\n");
			while ((input = getchar()) != '\n' && input != EOF);
			continue;
		}

		switch (whichFortune) {
		case 1:
			system("cls");
			Todayfortune();
			break;
		case 2:
			system("cls");
			RandomNum();
			break;
		case 3:
			system("cls");
			printf("운세목록을 선택했습니다.\n");
			FortuneList();
			break;
		case 4:
			system("cls");
			printf("~ 이용해주셔서 감사합니다 ~\n\n");
			break;
		default:
			printf("\nERROR: 1~4번 중에 선택해주세요.\n\n");
			continue;
		}
		break;
	}
}

void Warningtarot() {
	SetColor(4); //빨강
	printf("주의!\n");
	SetColor(7); //하양
	printf("타로카드는 정방향 메이저 카드로만 진행됩니다.");
	printf("\n\n시작하려면 'g'를 눌러주세요...");
	while (1) {
		char start = getch();
		if (start == 'g' || start == 'G') {
			break;
		}
	}

	system("cls");
	RandomNum();
}

void RandomNum() {
	int UserNum;

	//0부터 21까지의 난수 생성
	srand(time(NULL));
	int TarotNum = rand() % 22;

	//타로카드 뽑기(0~21)
	SetColor(5); //자주
	printf("당신의 운세가 될 타로카드를 섞고 있습니다...\n");
	fflush(stdout);
	Sleep(6000); //6초 후에 넘어가기
	system("cls");

	SetColor(7);
	printf("0부터 21 중에 원하는 숫자를 입력해주세요.\n");
	printf(">> ");

	while (scanf("%d", &UserNum) != 1 || UserNum < 0 || UserNum > 21) {
		printf("\nERROR: 0과 21 사이의 숫자여야 합니다.\n");
		// 입력 버퍼 비우기
		while (getchar() != '\n');
		printf(">> ");
	}

	boundaryShow();
	printf("\n    뽑힌 메이저 카드의 숫자: %d\n\n", TarotNum);
	boundaryShow();
	printf("\n해설:\n");

	switch (TarotNum) {
	case 0:
		SetColor(14); //밝은 노랑
		printf("The Fool(광대)\n\n");
		LateShow();
		SetColor(7);
		printf("광대 카드는 '새로운 시작'을 상징합니다.\n");
		LateShow();
		printf("지금 생각하고 있는 어떠한 일을 과감하게 도전해보시는 것을 추천합니다.\n");
		LateShow();
		printf("그러나, 무모한 도전보다는 철저한 준비를 통한 도전을 더 추천하는 바입니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 1:
		SetColor(14);
		printf("The Magician(마법사)\n\n");
		LateShow();
		SetColor(7);
		printf("마법사 카드는 '모든 사물, 사업의 시작점'을 상징합니다.\n");
		LateShow();
		printf("당신은 당신의 길을 찾을 수 있도록 돕는 훌륭한 조력자를 만날 수 있을 것입니다.\n");
		LateShow();
		printf("혹은 당신 스스로의 경험 속에서 해답을 찾을 수 있게 될 것입니다.\n");
		LateShow();
		printf("만약 새로운 일을 시작하는 단계라면 좋은 인연을 만난다는 징조이기도 합니다.\n");
		LateShow();
		printf("그러나, 타인의 도움에 의존하기보다 자신의 발전을 위해 스스로 더 노력해야 합니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 2:
		SetColor(14);
		printf("The High Priestess(여사제)\n\n");
		LateShow();
		SetColor(7);
		printf("여사제 카드는 '지식, 현명'을 상징합니다.\n");
		LateShow();
		printf("여사제는 잠재의식의 수호자로서 숨겨진 신비에 대한 신성한 지식을 제공합니다.\n");
		LateShow();
		printf("즉, 당신의 문제에 대한 해답을 얻기 위해 당신 자신의 내부를 깊숙히 들여다 볼 필요성이 있음을 시사합니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 3:
		SetColor(14);
		printf("The Empress(여황제)\n\n");
		LateShow();
		SetColor(7);
		printf("여황제 카드는 '풍요, 가정과 가족의 사랑'을 상징합니다.\n");
		LateShow();
		printf("여황제 카드는 당신이나 당신과 가까운 누군가가 임신 중이거나, 곧 임신할 것임을 암시합니다.\n");
		LateShow();
		printf("혹은 새로운 생각이나 새로운 현실의 출생으로도 해석될 수 있습니다.\n");
		LateShow();
		printf("즉, 당신의 모든 노고가 결국 성과를 거두게 되며");
		LateShow();
		printf("현재 당신이 느끼고 있을지도 모르는 재정 불안도 곧 사라지게 될 것임을 나타냅니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 4:
		SetColor(14);
		printf("The Emperor(황제)\n\n");
		LateShow();
		SetColor(7);
		printf("황제 카드는 '가부장제, 물질적인 힘, 보호'를 상징합니다.\n");
		LateShow();
		printf("황제는 자신감과 권위를 풍기는 남성의 모습인데,");
		LateShow();
		printf("수 많은 어려움에도 불구하고 황제 모습처럼 '목적 달성'과 '성공의 가능성'을 강하게 암시하고 있습니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 5:
		SetColor(14);
		printf("The Hierophant(교황)\n\n");
		LateShow();
		SetColor(7);
		printf("교황 카드는 '관습, 친절, 현명'을 상징합니다.\n");
		LateShow();
		printf("당신 내면의 정신적인 삶과 선입견 등을 다시 한 번 되돌아 볼 필요가 있습니다.\n");
		LateShow();
		printf("근본적인 것을 다시 생각해 봐야 할 수도 있습니다.\n");
		LateShow();
		printf("그렇지 않으면, 당신의 발로 스스로 이 세상에 우뚝 설 수 있는 새로운 방법을 배워야 할 지도 모릅니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 6:
		SetColor(13);
		printf("The Lovers(연인)\n\n");
		LateShow();
		SetColor(7);
		printf("연인 카드는 '사랑, 새로운 관계의 형성'을 상징합니다.\n");
		LateShow();
		printf("연인 카드는 당신이 사랑을 하고 있다면 당신의 연인과 함께 시련을 극복하고");
		LateShow();
		printf("서로에게 힘을 실어줄 수 있음을 의미합니다.\n");
		LateShow();
		printf("만약 당신이 사랑을 하고 있지 않다면 당신과 깊은 신뢰를 가지고");
		LateShow();
		printf("깊은 사랑을 할 수 있는 상대가 곧 나타날 것임을 암시하고 있습니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 7:
		SetColor(14);
		printf("The Lovers(전차)\n\n");
		LateShow();
		SetColor(7);
		printf("전차 카드는 '승리, 정복, 지배'를 상징합니다.\n");
		LateShow();
		printf("전차는 끝까지 노력하겠다는 당신의 결의를 보여줍니다.\n");
		LateShow();
		printf("성공은 시련과 고난 넘어에서 당신을 기다리고 있기에");
		LateShow();
		printf("자신의 목표에 재투자하고, 야망을 두 배로 늘릴 필요가 있습니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 8:
		SetColor(14);
		printf("Strength(힘)\n\n");
		LateShow();
		SetColor(7);
		printf("힘 카드는 '용기, 자신감, 열정'을 상징합니다.\n");
		LateShow();
		printf("힘 카드는 당신이 이미 목표에 달성하기 위한 특성을 갖추고 있으며,");
		LateShow();
		printf("인생의 다음 단계를 밟을 준비가 되어 있다는 것을 나타냅니다.\n");
		LateShow();
		printf("앞으로 많은 도전들이 있겠지만, 당신은 당신의 길에 있는 모든 장애물들을 쉽게 극복할 수 있을 것입니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 9:
		SetColor(14);
		printf("The Hermit(은둔자)\n\n");
		LateShow();
		SetColor(7);
		printf("은둔자 카드는 '현명한 판단'을 상징합니다.\n");
		LateShow();
		printf("은둔자는 어려운 시기에 당신을 인도하는 선지자이며, 당신에게 양심의 소리를 전하는 예언가이기도 합니다.\n");
		LateShow();
		printf("이는 당신에게 정신적인 도움을 주는 사람이 주위에 나타나거나,");
		LateShow();
		printf("당신의 내면 속에서 당신이 찾고자 하는 답을 찾게 될 것임을 시사합니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 10:
		SetColor(14);
		printf("Wheel of Fortune(운명의 수레바퀴)\n\n");
		LateShow();
		SetColor(7);
		printf("운명의 수레바퀴 카드는 '선과 악'을 상징합니다.\n");
		LateShow();
		printf("운명의 수레바퀴 카드는 당신의 인생이 더 나은 방향으로 변화할 것임을 암시합니다.\n");
		LateShow();
		printf("하지만, 이 카드는 인생이 순환 속에서 작동한다는 것을 상기시켜 주기도 하기 때문에.");
		LateShow();
		printf("갑작스러운 변화에 대비하고, 행운과 불운은 모두 일시적인 것이라는 것을 기억해야 합니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 11:
		SetColor(14);
		printf("Justice(정의)\n\n");
		LateShow();
		SetColor(7);
		printf("정의 카드는 '균형, 조화'를 상징합니다.\n");
		LateShow();
		printf("당신에게 내려진 무언가의 결정은 공정하고 정직하게 내려질 것이며, 당신은 그 결과를 존중해야 합니다.\n");
		LateShow();
		printf("만약, 당신에게 분쟁이 일어났다면 모든 분쟁은 당신에게 유리하게 해결될 것임을 나타냅니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 12:
		SetColor(4);
		printf("The Hanged Man(매달린 사람)\n\n");
		LateShow();
		SetColor(7);
		printf("매달린 사람 카드는 '희생, 후회, 회개'를 상징합니다.\n");
		LateShow();
		printf("매달린 사람 카드는 당신이 자신을 해방시키기 위해 필요한 틀에 박혀 있거나");
		LateShow();
		printf("부정적인 심리 상태에 있는 불행한 상황에 처해 있다는 것을 의미합니다.\n");
		LateShow();
		printf("어떤 길을 택할 지에 대한 불확실성으로도 해석할 수 있습니다.\n");
		LateShow();
		printf("당신의 관점을 바꾸기 위해 잠시 자신 밖으로 나가는 것을 고려해보고, 무엇이 당신의 발전을 방해하는지 알아야 합니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 13:
		SetColor(14);
		printf("Death(죽음)\n\n");
		LateShow();
		SetColor(7);
		printf("죽음 카드는 '새로운 시작'을 상징합니다.\n");
		LateShow();
		printf("대부분의 사람들이 꺼려하는 죽음 카드는 오히려 새로운 시작을 암시하는 긍정적인 카드입니다.\n");
		LateShow();
		printf("새로운 시작, 즉 한 사이클의 삶이 끝나고 새로운 사이클이 시작됨을 나타냅니다.\n");
		LateShow();
		printf("하지만, 미래를 깨닫기 위해선 먼저 과거를 떠나는 법을 배워야 합니다.\n");
		LateShow();
		printf("일단 일이 성취되면, 잿더미에서 솟아오르는 봉황처럼 당신은 재탄생을 경험하게 될 것입니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 14:
		SetColor(14);
		printf("Temperance(절제)\n\n");
		LateShow();
		SetColor(7);
		printf("절제 카드는 '균형, 안정, 절제'를 상징합니다.\n");
		LateShow();
		printf("절제 카드는 상황이 어려워질 때, 당신은 차분하고 이성적인 자세를 유지할 수 있고,\n");
		printf("스트레스를 이겨낼 수 있는 사람이라는 것을 나타냅니다.\n");
		LateShow();
		printf("당신은 상황의 전체를 분명하게 볼 수 있는 능력을 가지고 있으며,");
		LateShow();
		printf("당신이 탐험하기 위해 선택한 삶의 영역에서 상당한 발전을 누릴 수 있습니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 15:
		SetColor(4);
		printf("The Devil(악마)\n\n");
		LateShow();
		SetColor(7);
		printf("악마 카드는 '유혹, 욕망'를 상징합니다.\n");
		LateShow();
		printf("지금 자신이 무언가에 집착하거나 빠져있지 않은지 잘 살펴 보아야 합니다.\n");
		LateShow();
		printf("부정적인 것에 빠져있을 확률이 다소 높으므로");
		LateShow();
		printf("주변에 요청하여 부정적인 것에서 즉시 빠져나올 수 있도록 해야 합니다.\n");
		LateShow();
		printf("또한, 계속 부정적인 요소에 빠져있지 않기 위해 꾸준히 노력해야 합니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 16:
		SetColor(4);
		printf("The Tower(탑)\n\n");
		LateShow();
		SetColor(7);
		printf("탑 카드는 '뜻하지 않은 재앙'을 상징합니다.\n");
		LateShow();
		printf("탑 카드는 일반적으로 어둡고 위협적인 카드이며,");
		LateShow();
		printf("예기치 못한 심각한 정신적 충격을 주는 사건의 전조일 수도 있습니다.\n");
		LateShow();
		printf("또한, 탑 카드는 불쾌한 진실로부터 더 이상 숨을 수 없다는 경고의 역할도 합니다.\n");
		LateShow();
		printf("곧 직면하게 될 불쾌한 진실은 당신의 감정의 각성 촉매제 역할을 하게 될 것이며,");
		LateShow();
		printf("그것은 당신의 길에 결정적인 중요한 변화가 될 것입니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 17:
		SetColor(14);
		printf("The Star(별)\n\n");
		LateShow();
		SetColor(7);
		printf("별 카드는 '희망, 행복'을 상징합니다.\n");
		LateShow();
		printf("별 카드는 운이 좋아져 지금 선택하는 것이 좋은 결과를 가져올 것임을 의미합니다.\n");
		LateShow();
		printf("당신은 내면 속에서 따라야 할 올바른 길을 이미 알고 있습니다.\n");
		LateShow();
		printf("그 올바른 길을 따라 가다보면 분명 좋은 일이 생길 것입니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 18:
		SetColor(4);
		printf("The Moon(달)\n\n");
		LateShow();
		SetColor(7);
		printf("달 카드는 '신비, 의심'을 상징합니다.\n");
		LateShow();
		printf("달 카드는 당신의 삶에서 어떠한 것들이나 사람이 겉과 속이 다르다는 것을 나타냅니다.\n");
		LateShow();
		printf("이는 당신의 포부나 계획에도 적용될 수 있습니다.\n");
		LateShow();
		printf("당신의 계획은 예상대로 이루어지지 않을 수도 있고, 거의 탈선될 수도 있습니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 19:
		SetColor(14);
		printf("The Sun(태양)\n\n");
		LateShow();
		SetColor(7);
		printf("태양 카드는 '영광, 영감'을 상징합니다.\n");
		LateShow();
		printf("태양 카드는 기운을 돋우는 신호로,");
		LateShow();
		printf("긍정적인 영향이 당신에게 흥미로운 새로운 기회를 가져다줄 것입니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 20:
		SetColor(14);
		printf("Judgement(심판)\n\n");
		LateShow();
		SetColor(7);
		printf("심판 카드는 '재탄생, 선택'을 상징합니다.\n");
		LateShow();
		printf("심판 카드는 재탄생, 즉 변화를 위한 능력을 강조합니다.\n");
		LateShow();
		printf("심판 카드는 순간적인 변화나 고된 시련이 닥치게 됨을 나타낼 수 있습니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 21:
		SetColor(14);
		printf("The World(세계)\n\n");
		LateShow();
		SetColor(7);
		printf("세계 카드는 '완벽함, 성공, 성취'를 상징합니다.\n");
		LateShow();
		printf("세계 카드는 당신이 여행의 막바지에 다다랐으며, 당신이 승리할 것이라는 신호입니다.\n");
		LateShow();
		printf("자신감이 치솟고 있지만, 아직 노력을 멈춰서는 안됩니다.\n");
		LateShow();
		printf("만약 멈추지 않고 계속해서 노력해 나간다면, 당신의 야망과 꼼꼼한 계획은 곧 성과를 거둘 것입니다.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	}
}

void FortuneList() {
	printf("\n");
	BackChoose();
}

struct UserInfo {
	char name[50];
	int year;
	int month;
	int day;
};

int main() {
	struct UserInfo u;
	printf("당신의 정보를 입력해주세요\n");
	printf("Name: ");
	scanf("%49s", u.name);

	//year 제한
	while (1) {
		printf("Year: ");
		scanf("%d", &u.year);
		if (u.year >= 1900 && u.year <= 2024) { break; }
		else {
			printf("\nERROR: 1900~2024년 사이로 입력해주세요.\n");
		}
	}
	//month 제한
	while (1) {
		printf("Month: ");
		scanf("%d", &u.month);
		if (u.month >= 1 && u.month <= 12) { break; }
		else {
			printf("\nERROR: 1~12월 사이로 입력해주세요.\n");
		}
	}
	//day 제한
	while (1) {
		printf("Day: ");
		scanf("%d", &u.day);
		if (u.day >= 1 && u.day <= 31) { break; }
		else {
			printf("\nERROR: 1~31일 사이로 입력해주세요.\n");
		}
	}

	//계속하기
	printf("\n계속하려면 'g'를 눌러주세요...");
	while (1) {
		char CONTINUE = getch();
		if (CONTINUE == 'g' || CONTINUE == 'G') {
			break;
		}
	}

	system("cls");
	SetColor(8);
	printf("~ Your Infomation ~");
	SetColor(7);
	printf("\n\n이름: %s\n생년월일: %d/%d/%d\n", u.name, u.year, u.month, u.day);
	getchar(); //아무 키 누르기 전까지 화면 출력 유지
	printf("\n");

	chooseFortune();
	return 0;
}