#include "main.h"

//イニシャライズ
void CObjPlayer::Init() {
	char* token;
	int i = 0;


	ifstream ifw("1-1.bin", std::ios::in | std::ios::binary);

	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	ifw.close();

	
	

	token = strtok(tmpstr, "\n");
	while (token != NULL) {
		strcpy(strsave[i], token);
		token = strtok(NULL, "\n");
		i++;
	}

	for (int j = 0; j < i; j++) {
		if(strsave[j][strlen(strsave[j]) - 1] == '\r')
			strsave[j][strlen(strsave[j]) - 1] = '\0';
	}

	for (int w = 0; w < i; w++) {
		test.push_back(strsave[w]);
	}
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

	for(int f = 0;f < linecount;f++)
		Font()->StrDraw(((char*)test[f].c_str()), 0, f*16, 16, col);

	//Font()->StrDraw(strsave[1], 0, 16, 16, col);
	//Font()->StrDraw(strsave[2], 0, 32, 16, col);
	//Font()->StrDraw(strsave[3], 0, 48, 16, col);
}