#include<bangtal.h>
using namespace bangtal;

int main() {
	//����� ����
	auto scene1 = Scene::create("��1", "Images/���-1.png");
	auto scene2 = Scene::create("��2", "Images/���-2.png");

	//���� �����.
	auto door1 = Object::create("Images/��-������-����.png",scene1,800,270);
	auto door2 = Object::create("Images/��-����-����.png", scene2, 320, 270);
	auto door3 = Object::create("Images/��-������-����.png", scene2, 1200, 230,false);
	door3->setScale(0.3f);
	//����ġ�� �����.
	auto button = Object::create("Images/����ġ.jpg", scene2, 870, 440);
	button->setScale(0.2f);
	
	door1->setOnMouseCallback([&](ObjectPtr, int x, int y, MouseAction action)->bool {
		
		door1->setImage("Images/��-������-����.png");
		scene2->enter();
		showMessage("������ ���� ã�ƺ�����!");
		return true;
		});

	door2->setOnMouseCallback([&](ObjectPtr, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
		});

	auto lighted = true;
	button->setOnMouseCallback([&](ObjectPtr, int x, int y, MouseAction action)->bool {
		if (lighted)
		{
			scene2->setLight(0.3f);
			lighted = false;
			door3->show();
		}
		else{
			scene2->setLight(1.0f);
			lighted = true;
			door3->hide();
		}

		return true;
		});
	door3->setOnMouseCallback([&](ObjectPtr, int x, int y, MouseAction action)->bool {
		if (lighted==false) {
	
			endGame();
		}
				return true;
		});

	startGame(scene1);
	return 0;
}