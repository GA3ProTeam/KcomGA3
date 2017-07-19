#include "main.h"

//イニシャライズ
void CObjPlayer::Init() {
	char* token;
	int i = 0;

	//文字データ読み込み
	ifstream ifw("Text\\sion1\\sion1_start.bin", std::ios::in | std::ios::binary);
	

	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	ifw.close();

	//最後の空白行を削除
	if (tmpstr[textlen - 2] == '\r') {
		tmpstr[textlen - 2] = '\0';
		linecount--;
	}
	
	//改行文字で切断
	token = strtok(tmpstr, "\n");
	while (token != NULL) {
		strcpy(strsave[i], token);
		token = strtok(NULL, "\n");
		i++;
	}

	//改行文字を排除
	for (int j = 0; j < i; j++) {
		if(strsave[j][strlen(strsave[j]) - 1] == '\r')
			strsave[j][strlen(strsave[j]) - 1] = '\0';
	}

	//vector形にまとめる
	for (int w = 0; w < i; w++) {
		test.push_back(strsave[w]);
	}

	//制御文字削除（検出）
	std::vector<std::string>::iterator itr = test.begin();
	while (itr != test.end()) {
		if (strchr((*itr).c_str(), '[')) {
			itr = test.erase(itr);
		}
		else {
			itr++;
		}
	}
}

//デストラクタ
void CObjPlayer::Destructor() {

}

//アクション
void CObjPlayer::Action() {
	//DialogBox(User()->p_hInstance , MAKEINTRESOURCE(IDD_DIALOG1), User()->p_hWnd , User()->p_DlgProc);

	//Font()->StrDraw(User()->dlgIn, 0, WINDOW_SIZE_H/2, 32, col);
}

//ドロー
void CObjPlayer::Draw() {
	//カラー情報
	//float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//for(DWORD f = 0;f < test.size();f++)
	//	Font()->StrDraw(((char*)test[f].c_str()), 0, f*16, 16, col);

	//Font()->StrDraw(User()->dlgIn, 0, WINDOW_SIZE_H/2, 32, col);

	//Font()->StrDraw(strsave[1], 0, 16, 16, col);
	//Font()->StrDraw(strsave[2], 0, 32, 16, col);
	//Font()->StrDraw(strsave[3], 0, 48, 16, col);
}