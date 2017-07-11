#include "../main.h"

void CTextManager::LoadText()
{
	char* token;
	int i = 0;
	char filePath[64];

	//文字データ読み込み
	sprintf_s(filePath, "Text\\%s\\%s.bin", ENUMSTR(koune1), ENUMSTR(koune1_start));
	ifstream ifw(filePath, std::ios::in | std::ios::binary);

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
		if (strsave[j][strlen(strsave[j]) - 1] == '\r')
			strsave[j][strlen(strsave[j]) - 1] = '\0';
	}

	//vector形にまとめる
	for (int w = 0; w < i; w++) {
		tmpData.push_back(strsave[w]);
	}

	//制御文字削除（検出）
	//std::vector<std::string>::iterator itr = tmpData.begin();
	//while (itr != tmpData.end()) {
	//	if (strchr((*itr).c_str(), '[')) {
	//		itr = tmpData.erase(itr);
	//	}
	//	else {
	//		itr++;
	//	}
	//}
}