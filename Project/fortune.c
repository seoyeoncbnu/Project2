#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> //�ܼ�â(getch)
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
	Sleep(2000); //2�� �ʰ� ���
	printf("\n");
}

void choiceShow() {
	printf("      ~ Choose your Fortune ~\n\n");
	boundaryShow();
	printf("\n\t1. ������ �������\n\t2. Ÿ��ī�� �̱�\n\t3. ��Ϻ���\n\t4. ������\n\n");
	boundaryShow();
	printf(">> ");
}

void BackChoose() {
	printf("�ڷΰ����� 'b'�� �����ּ���...");
	while (1) {
		char back = getch();
		if (back == 'b' || back == 'B') {
			break;
		}
	}
	system("cls");
	chooseFortune(); //b�� ���� �������� �ٽ� �̵�
}

void Todayfortune() {
	// ���� ������ ���� �õ� ����
	srand(time(NULL));

	//0���� 5������ ���� ���� (���� ����)
	int numStars = rand() % 6;

	printf("      ~ ������ ");
	SetColor(10);
	printf("�������");
	SetColor(7);
	printf("��? ~\n\n");
	boundaryShow();
	printf("\n\t������ ����: ");

	fflush(stdout);
	Sleep(2000);

	//�� 5���� �ڸ����� ���� ������ŭ ���� �����Ͽ� ���
	for (int i = 0; i < 5; i++) {
		if (i < numStars) {
			printf("��");
		}
		else {
			printf("��");
		}
	}

	//1���� 50������ ���� ����
	int luckyNumber = (rand() % 50) + 1;
	printf("\n\t����� ��ȣ: ");
	fflush(stdout);
	Sleep(2000);
	printf("%d\n\n", luckyNumber);
	boundaryShow();

	printf("\n�ؼ�:");
	LateShow();

	//���� ������ ���� �޽��� ���
	switch (numStars) {
	case 0:
		printf("���� �Ϸ� �����ϼ���. ����� ���ϴ�!\n");
		break;
	case 1:
		printf("������ ����� ������ ���� �� �ֽ��ϴ�. �ʹ� �������� ������.\n");
		break;
	case 2:
		printf("�ټ� �Ҿ��� �Ϸ簡 �� �� �ֽ��ϴ�. ���� �Ǽ����� �����ϼ���.\n");
		break;
	case 3:
		printf("����� �Ϸ�����, �ټ� ��ȭ�ο� ���� �� ���Դϴ�.\n");
		break;
	case 4:
		printf("����� ���Դϴ�! �ϰ� �;��� ���� ���������� �غ�����!\n");
		break;
	case 5:
		printf("�����մϴ�! ������ ���ƴ� ���� ��! �ڽŰ��� ������ ���������� Ȱ���غ�����!\n");
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
		//���ڰ� �ƴ� ���
		if (scanf("%d", &whichFortune) != 1) {
			printf("\nERROR: ���ڸ� �Է����ּ���.\n\n");
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
			printf("������ �����߽��ϴ�.\n");
			FortuneList();
			break;
		case 4:
			system("cls");
			printf("~ �̿����ּż� �����մϴ� ~\n\n");
			break;
		default:
			printf("\nERROR: 1~4�� �߿� �������ּ���.\n\n");
			continue;
		}
		break;
	}
}

void Warningtarot() {
	SetColor(4); //����
	printf("����!\n");
	SetColor(7); //�Ͼ�
	printf("Ÿ��ī��� ������ ������ ī��θ� ����˴ϴ�.");
	printf("\n\n�����Ϸ��� 'g'�� �����ּ���...");
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

	//0���� 21������ ���� ����
	srand(time(NULL));
	int TarotNum = rand() % 22;

	//Ÿ��ī�� �̱�(0~21)
	SetColor(5); //����
	printf("����� ��� �� Ÿ��ī�带 ���� �ֽ��ϴ�...\n");
	fflush(stdout);
	Sleep(6000); //6�� �Ŀ� �Ѿ��
	system("cls");

	SetColor(7);
	printf("0���� 21 �߿� ���ϴ� ���ڸ� �Է����ּ���.\n");
	printf(">> ");

	while (scanf("%d", &UserNum) != 1 || UserNum < 0 || UserNum > 21) {
		printf("\nERROR: 0�� 21 ������ ���ڿ��� �մϴ�.\n");
		// �Է� ���� ����
		while (getchar() != '\n');
		printf(">> ");
	}

	boundaryShow();
	printf("\n    ���� ������ ī���� ����: %d\n\n", TarotNum);
	boundaryShow();
	printf("\n�ؼ�:\n");

	switch (TarotNum) {
	case 0:
		SetColor(14); //���� ���
		printf("The Fool(����)\n\n");
		LateShow();
		SetColor(7);
		printf("���� ī��� '���ο� ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("���� �����ϰ� �ִ� ��� ���� �����ϰ� �����غ��ô� ���� ��õ�մϴ�.\n");
		LateShow();
		printf("�׷���, ������ �������ٴ� ö���� �غ� ���� ������ �� ��õ�ϴ� ���Դϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 1:
		SetColor(14);
		printf("The Magician(������)\n\n");
		LateShow();
		SetColor(7);
		printf("������ ī��� '��� �繰, ����� ������'�� ��¡�մϴ�.\n");
		LateShow();
		printf("����� ����� ���� ã�� �� �ֵ��� ���� �Ǹ��� �����ڸ� ���� �� ���� ���Դϴ�.\n");
		LateShow();
		printf("Ȥ�� ��� �������� ���� �ӿ��� �ش��� ã�� �� �ְ� �� ���Դϴ�.\n");
		LateShow();
		printf("���� ���ο� ���� �����ϴ� �ܰ��� ���� �ο��� �����ٴ� ¡���̱⵵ �մϴ�.\n");
		LateShow();
		printf("�׷���, Ÿ���� ���� �����ϱ⺸�� �ڽ��� ������ ���� ������ �� ����ؾ� �մϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 2:
		SetColor(14);
		printf("The High Priestess(������)\n\n");
		LateShow();
		SetColor(7);
		printf("������ ī��� '����, ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("�������� �����ǽ��� ��ȣ�ڷμ� ������ �ź� ���� �ż��� ������ �����մϴ�.\n");
		LateShow();
		printf("��, ����� ������ ���� �ش��� ��� ���� ��� �ڽ��� ���θ� ����� �鿩�� �� �ʿ伺�� ������ �û��մϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 3:
		SetColor(14);
		printf("The Empress(��Ȳ��)\n\n");
		LateShow();
		SetColor(7);
		printf("��Ȳ�� ī��� 'ǳ��, ������ ������ ���'�� ��¡�մϴ�.\n");
		LateShow();
		printf("��Ȳ�� ī��� ����̳� ��Ű� ����� �������� �ӽ� ���̰ų�, �� �ӽ��� ������ �Ͻ��մϴ�.\n");
		LateShow();
		printf("Ȥ�� ���ο� �����̳� ���ο� ������ ������ε� �ؼ��� �� �ֽ��ϴ�.\n");
		LateShow();
		printf("��, ����� ��� ��� �ᱹ ������ �ŵΰ� �Ǹ�");
		LateShow();
		printf("���� ����� ������ �������� �𸣴� ���� �Ҿȵ� �� ������� �� ������ ��Ÿ���ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 4:
		SetColor(14);
		printf("The Emperor(Ȳ��)\n\n");
		LateShow();
		SetColor(7);
		printf("Ȳ�� ī��� '��������, �������� ��, ��ȣ'�� ��¡�մϴ�.\n");
		LateShow();
		printf("Ȳ���� �ڽŰ��� ������ ǳ��� ������ ����ε�,");
		LateShow();
		printf("�� ���� ����򿡵� �ұ��ϰ� Ȳ�� ���ó�� '���� �޼�'�� '������ ���ɼ�'�� ���ϰ� �Ͻ��ϰ� �ֽ��ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 5:
		SetColor(14);
		printf("The Hierophant(��Ȳ)\n\n");
		LateShow();
		SetColor(7);
		printf("��Ȳ ī��� '����, ģ��, ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("��� ������ �������� ��� ���԰� ���� �ٽ� �� �� �ǵ��� �� �ʿ䰡 �ֽ��ϴ�.\n");
		LateShow();
		printf("�ٺ����� ���� �ٽ� ������ ���� �� ���� �ֽ��ϴ�.\n");
		LateShow();
		printf("�׷��� ������, ����� �߷� ������ �� ���� ��� �� �� �ִ� ���ο� ����� ����� �� ���� �𸨴ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 6:
		SetColor(13);
		printf("The Lovers(����)\n\n");
		LateShow();
		SetColor(7);
		printf("���� ī��� '���, ���ο� ������ ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("���� ī��� ����� ����� �ϰ� �ִٸ� ����� ���ΰ� �Բ� �÷��� �غ��ϰ�");
		LateShow();
		printf("���ο��� ���� �Ǿ��� �� ������ �ǹ��մϴ�.\n");
		LateShow();
		printf("���� ����� ����� �ϰ� ���� �ʴٸ� ��Ű� ���� �ŷڸ� ������");
		LateShow();
		printf("���� ����� �� �� �ִ� ��밡 �� ��Ÿ�� ������ �Ͻ��ϰ� �ֽ��ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 7:
		SetColor(14);
		printf("The Lovers(����)\n\n");
		LateShow();
		SetColor(7);
		printf("���� ī��� '�¸�, ����, ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("������ ������ ����ϰڴٴ� ����� ���Ǹ� �����ݴϴ�.\n");
		LateShow();
		printf("������ �÷ð� �� �Ѿ�� ����� ��ٸ��� �ֱ⿡");
		LateShow();
		printf("�ڽ��� ��ǥ�� �������ϰ�, �߸��� �� ��� �ø� �ʿ䰡 �ֽ��ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 8:
		SetColor(14);
		printf("Strength(��)\n\n");
		LateShow();
		SetColor(7);
		printf("�� ī��� '���, �ڽŰ�, ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("�� ī��� ����� �̹� ��ǥ�� �޼��ϱ� ���� Ư���� ���߰� ������,");
		LateShow();
		printf("�λ��� ���� �ܰ踦 ���� �غ� �Ǿ� �ִٴ� ���� ��Ÿ���ϴ�.\n");
		LateShow();
		printf("������ ���� �������� �ְ�����, ����� ����� �濡 �ִ� ��� ��ֹ����� ���� �غ��� �� ���� ���Դϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 9:
		SetColor(14);
		printf("The Hermit(������)\n\n");
		LateShow();
		SetColor(7);
		printf("������ ī��� '������ �Ǵ�'�� ��¡�մϴ�.\n");
		LateShow();
		printf("�����ڴ� ����� �ñ⿡ ����� �ε��ϴ� �������̸�, ��ſ��� ����� �Ҹ��� ���ϴ� �����̱⵵ �մϴ�.\n");
		LateShow();
		printf("�̴� ��ſ��� �������� ������ �ִ� ����� ������ ��Ÿ���ų�,");
		LateShow();
		printf("����� ���� �ӿ��� ����� ã���� �ϴ� ���� ã�� �� ������ �û��մϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 10:
		SetColor(14);
		printf("Wheel of Fortune(����� ��������)\n\n");
		LateShow();
		SetColor(7);
		printf("����� �������� ī��� '���� ��'�� ��¡�մϴ�.\n");
		LateShow();
		printf("����� �������� ī��� ����� �λ��� �� ���� �������� ��ȭ�� ������ �Ͻ��մϴ�.\n");
		LateShow();
		printf("������, �� ī��� �λ��� ��ȯ �ӿ��� �۵��Ѵٴ� ���� ������ �ֱ⵵ �ϱ� ������.");
		LateShow();
		printf("���۽����� ��ȭ�� ����ϰ�, ���� �ҿ��� ��� �Ͻ����� ���̶�� ���� ����ؾ� �մϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 11:
		SetColor(14);
		printf("Justice(����)\n\n");
		LateShow();
		SetColor(7);
		printf("���� ī��� '����, ��ȭ'�� ��¡�մϴ�.\n");
		LateShow();
		printf("��ſ��� ������ ������ ������ �����ϰ� �����ϰ� ������ ���̸�, ����� �� ����� �����ؾ� �մϴ�.\n");
		LateShow();
		printf("����, ��ſ��� ������ �Ͼ�ٸ� ��� ������ ��ſ��� �����ϰ� �ذ�� ������ ��Ÿ���ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 12:
		SetColor(4);
		printf("The Hanged Man(�Ŵ޸� ���)\n\n");
		LateShow();
		SetColor(7);
		printf("�Ŵ޸� ��� ī��� '���, ��ȸ, ȸ��'�� ��¡�մϴ�.\n");
		LateShow();
		printf("�Ŵ޸� ��� ī��� ����� �ڽ��� �ع��Ű�� ���� �ʿ��� Ʋ�� ���� �ְų�");
		LateShow();
		printf("�������� �ɸ� ���¿� �ִ� ������ ��Ȳ�� ó�� �ִٴ� ���� �ǹ��մϴ�.\n");
		LateShow();
		printf("� ���� ���� ���� ���� ��Ȯ�Ǽ����ε� �ؼ��� �� �ֽ��ϴ�.\n");
		LateShow();
		printf("����� ������ �ٲٱ� ���� ��� �ڽ� ������ ������ ���� ����غ���, ������ ����� ������ �����ϴ��� �˾ƾ� �մϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 13:
		SetColor(14);
		printf("Death(����)\n\n");
		LateShow();
		SetColor(7);
		printf("���� ī��� '���ο� ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("��κ��� ������� �����ϴ� ���� ī��� ������ ���ο� ������ �Ͻ��ϴ� �������� ī���Դϴ�.\n");
		LateShow();
		printf("���ο� ����, �� �� ����Ŭ�� ���� ������ ���ο� ����Ŭ�� ���۵��� ��Ÿ���ϴ�.\n");
		LateShow();
		printf("������, �̷��� ���ݱ� ���ؼ� ���� ���Ÿ� ������ ���� ����� �մϴ�.\n");
		LateShow();
		printf("�ϴ� ���� ����Ǹ�, ����̿��� �ھƿ����� ��Ȳó�� ����� ��ź���� �����ϰ� �� ���Դϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 14:
		SetColor(14);
		printf("Temperance(����)\n\n");
		LateShow();
		SetColor(7);
		printf("���� ī��� '����, ����, ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("���� ī��� ��Ȳ�� ������� ��, ����� �����ϰ� �̼����� �ڼ��� ������ �� �ְ�,\n");
		printf("��Ʈ������ �̰ܳ� �� �ִ� ����̶�� ���� ��Ÿ���ϴ�.\n");
		LateShow();
		printf("����� ��Ȳ�� ��ü�� �и��ϰ� �� �� �ִ� �ɷ��� ������ ������,");
		LateShow();
		printf("����� Ž���ϱ� ���� ������ ���� �������� ����� ������ ���� �� �ֽ��ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 15:
		SetColor(4);
		printf("The Devil(�Ǹ�)\n\n");
		LateShow();
		SetColor(7);
		printf("�Ǹ� ī��� '��Ȥ, ���'�� ��¡�մϴ�.\n");
		LateShow();
		printf("���� �ڽ��� ���𰡿� �����ϰų� �������� ������ �� ���� ���ƾ� �մϴ�.\n");
		LateShow();
		printf("�������� �Ϳ� �������� Ȯ���� �ټ� �����Ƿ�");
		LateShow();
		printf("�ֺ��� ��û�Ͽ� �������� �Ϳ��� ��� �������� �� �ֵ��� �ؾ� �մϴ�.\n");
		LateShow();
		printf("����, ��� �������� ��ҿ� �������� �ʱ� ���� ������ ����ؾ� �մϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 16:
		SetColor(4);
		printf("The Tower(ž)\n\n");
		LateShow();
		SetColor(7);
		printf("ž ī��� '������ ���� ���'�� ��¡�մϴ�.\n");
		LateShow();
		printf("ž ī��� �Ϲ������� ��Ӱ� �������� ī���̸�,");
		LateShow();
		printf("����ġ ���� �ɰ��� ������ ����� �ִ� ����� ������ ���� �ֽ��ϴ�.\n");
		LateShow();
		printf("����, ž ī��� ������ ���Ƿκ��� �� �̻� ���� �� ���ٴ� ����� ���ҵ� �մϴ�.\n");
		LateShow();
		printf("�� �����ϰ� �� ������ ������ ����� ������ ���� �˸��� ������ �ϰ� �� ���̸�,");
		LateShow();
		printf("�װ��� ����� �濡 �������� �߿��� ��ȭ�� �� ���Դϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 17:
		SetColor(14);
		printf("The Star(��)\n\n");
		LateShow();
		SetColor(7);
		printf("�� ī��� '���, �ູ'�� ��¡�մϴ�.\n");
		LateShow();
		printf("�� ī��� ���� ������ ���� �����ϴ� ���� ���� ����� ������ ������ �ǹ��մϴ�.\n");
		LateShow();
		printf("����� ���� �ӿ��� ����� �� �ùٸ� ���� �̹� �˰� �ֽ��ϴ�.\n");
		LateShow();
		printf("�� �ùٸ� ���� ���� ���ٺ��� �и� ���� ���� ���� ���Դϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 18:
		SetColor(4);
		printf("The Moon(��)\n\n");
		LateShow();
		SetColor(7);
		printf("�� ī��� '�ź�, �ǽ�'�� ��¡�մϴ�.\n");
		LateShow();
		printf("�� ī��� ����� ��� ��� �͵��̳� ����� �Ѱ� ���� �ٸ��ٴ� ���� ��Ÿ���ϴ�.\n");
		LateShow();
		printf("�̴� ����� ���γ� ��ȹ���� ����� �� �ֽ��ϴ�.\n");
		LateShow();
		printf("����� ��ȹ�� ������ �̷������ ���� ���� �ְ�, ���� Ż���� ���� �ֽ��ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 19:
		SetColor(14);
		printf("The Sun(�¾�)\n\n");
		LateShow();
		SetColor(7);
		printf("�¾� ī��� '����, ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("�¾� ī��� ����� ����� ��ȣ��,");
		LateShow();
		printf("�������� ������ ��ſ��� ��̷ο� ���ο� ��ȸ�� �������� ���Դϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 20:
		SetColor(14);
		printf("Judgement(����)\n\n");
		LateShow();
		SetColor(7);
		printf("���� ī��� '��ź��, ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("���� ī��� ��ź��, �� ��ȭ�� ���� �ɷ��� �����մϴ�.\n");
		LateShow();
		printf("���� ī��� �������� ��ȭ�� ��� �÷��� ��ġ�� ���� ��Ÿ�� �� �ֽ��ϴ�.\n");
		LateShow();
		boundaryShow();
		BackChoose();
		break;
	case 21:
		SetColor(14);
		printf("The World(����)\n\n");
		LateShow();
		SetColor(7);
		printf("���� ī��� '�Ϻ���, ����, ����'�� ��¡�մϴ�.\n");
		LateShow();
		printf("���� ī��� ����� ������ �������� �ٴٶ�����, ����� �¸��� ���̶�� ��ȣ�Դϴ�.\n");
		LateShow();
		printf("�ڽŰ��� ġ�ڰ� ������, ���� ����� ���缭�� �ȵ˴ϴ�.\n");
		LateShow();
		printf("���� ������ �ʰ� ����ؼ� ����� �����ٸ�, ����� �߸��� �Ĳ��� ��ȹ�� �� ������ �ŵ� ���Դϴ�.\n");
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
	printf("����� ������ �Է����ּ���\n");
	printf("Name: ");
	scanf("%49s", u.name);

	//year ����
	while (1) {
		printf("Year: ");
		scanf("%d", &u.year);
		if (u.year >= 1900 && u.year <= 2024) { break; }
		else {
			printf("\nERROR: 1900~2024�� ���̷� �Է����ּ���.\n");
		}
	}
	//month ����
	while (1) {
		printf("Month: ");
		scanf("%d", &u.month);
		if (u.month >= 1 && u.month <= 12) { break; }
		else {
			printf("\nERROR: 1~12�� ���̷� �Է����ּ���.\n");
		}
	}
	//day ����
	while (1) {
		printf("Day: ");
		scanf("%d", &u.day);
		if (u.day >= 1 && u.day <= 31) { break; }
		else {
			printf("\nERROR: 1~31�� ���̷� �Է����ּ���.\n");
		}
	}

	//����ϱ�
	printf("\n����Ϸ��� 'g'�� �����ּ���...");
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
	printf("\n\n�̸�: %s\n�������: %d/%d/%d\n", u.name, u.year, u.month, u.day);
	getchar(); //�ƹ� Ű ������ ������ ȭ�� ��� ����
	printf("\n");

	chooseFortune();
	return 0;
}