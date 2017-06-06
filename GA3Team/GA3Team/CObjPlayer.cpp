#include "main.h"

//イニシャライズ
void CObjPlayer::Init() {
	ifstream ifw("1-1.bin", std::ios::in | std::ios::binary);

	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	ifw.close();
}

//デストラクタ
void CObjPlayer::Destructor() {

}

//アクション
void CObjPlayer::Action() {

}

//ドロー
void CObjPlayer::Draw() {
	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font()->StrDraw("test", 0, 0, 16, col);
}