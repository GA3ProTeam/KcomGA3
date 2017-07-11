#include "../main.h"

void CTextManager::LoadText()
{
	char* token;
	int i = 0;
	char filePath[64];

	//�����f�[�^�ǂݍ���
	sprintf_s(filePath, "Text\\%s\\%s.bin", ENUMSTR(koune1), ENUMSTR(koune1_start));
	ifstream ifw(filePath, std::ios::in | std::ios::binary);

	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	ifw.close();

	//�Ō�̋󔒍s���폜
	if (tmpstr[textlen - 2] == '\r') {
		tmpstr[textlen - 2] = '\0';
		linecount--;
	}

	//���s�����Őؒf
	token = strtok(tmpstr, "\n");
	while (token != NULL) {
		strcpy(strsave[i], token);
		token = strtok(NULL, "\n");
		i++;
	}

	//���s������r��
	for (int j = 0; j < i; j++) {
		if (strsave[j][strlen(strsave[j]) - 1] == '\r')
			strsave[j][strlen(strsave[j]) - 1] = '\0';
	}

	//vector�`�ɂ܂Ƃ߂�
	for (int w = 0; w < i; w++) {
		tmpData.push_back(strsave[w]);
	}

	//���䕶���폜�i���o�j
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