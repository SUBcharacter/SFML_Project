#pragma once
// �ʿ��� ���̺귯�� ����
// 필요한 라이브러리 선언
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <vector>
#include <Windows.h>
#include <unordered_map>
#include <utility>


using namespace std;
using namespace sf;


// ���������� ���̴� enum, ����ü ���� ����

struct Pos
{
	float x;
	float y;
};

// 공통적으로 쓰이는 enum, 구조체 선언 공간
