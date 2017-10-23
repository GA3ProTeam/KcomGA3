#include "../main.h"

void COverlay::InitLoad()
{
	//Image
	image->LoadImageEx("各ステージで使用するギミック仮画像.png", 58, TEX_SIZE_1024);
	image->LoadImageEx("bb.png", 59, TEX_SIZE_512);
	image->LoadImageEx("orga2.png", 60, TEX_SIZE_1024);
	image->LoadImageEx("yjt.png", 61, TEX_SIZE_512);
	image->LoadImageEx("orga.png", 62, TEX_SIZE_512);
	image->LoadImageEx("atsumori.png", 63, TEX_SIZE_256);

	//空白画像
	image->LoadImageEx("null.png", 0, TEX_SIZE_512);
	//コウネ1----------------------------------
	image->LoadImageEx("おじいさんc.png", 1, TEX_SIZE_512);
	image->LoadImageEx("マンホール.png", 2, TEX_SIZE_1024);
	image->LoadImageEx("マンホールの穴.png", 3, TEX_SIZE_1024);
	//コウネ2-----------------------------------
	image->LoadImageEx("強気少年.png", 4, TEX_SIZE_512);
	image->LoadImageEx("女の子.png", 5, TEX_SIZE_512);
	//コウネ3----------------------------------------
	image->LoadImageEx("優しい少女.png", 6, TEX_SIZE_512);
	//シオン2--------------------------------------
	image->LoadImageEx("イヤホン男.png", 7, TEX_SIZE_512);
	image->LoadImageEx("自転車.png", 8, TEX_SIZE_512);
	image->LoadImageEx("イヤホン男自転車消防車.png", 30, TEX_SIZE_1024);
	//シオン3--------------------------------------
	image->LoadImageEx("おばあちゃんc.png", 9, TEX_SIZE_512);
	//シオン4--------------------------------------
	image->LoadImageEx("なぞなぞさん.png", 9, TEX_SIZE_512);
	//image->LoadImageEx("バイク.png", 9, TEX_SIZE_512);
	//image->LoadImageEx("シオン4ドア.png", 9, TEX_SIZE_512);
	//メルエル1-----------------------------------
	image->LoadImageEx("カツオc.png", EX_MERUERU_KATSUO, TEX_SIZE_512);
	image->LoadImageEx("ドアc.png", 12, TEX_SIZE_512);
	image->LoadImageEx("机.png", 13, TEX_SIZE_512);
	image->LoadImageEx("電子レンジ.png", 14, TEX_SIZE_512);
	image->LoadImageEx("博士c.png", 15, TEX_SIZE_512);
	//動物------------------------------------------
	image->LoadImageEx("動物まとめ.png", 16, TEX_SIZE_1024);
	//メインキャラクター----------------------------
	image->LoadImageEx("コウネ立ち.png", 17, TEX_SIZE_1024);
	image->LoadImageEx("シオン立ち.png", 18, TEX_SIZE_1024);
	image->LoadImageEx("メルエルc立ち.png", 19, TEX_SIZE_512);
	//データセレクト--------------------------------
	image->LoadImageEx("コウネ.png", 20, TEX_SIZE_1024);
	image->LoadImageEx("メルエル.png", 21, TEX_SIZE_512);
	//吹き出し系統-----------------------------------
	image->LoadImageEx("アイコン.png", 22, TEX_SIZE_1024);
	image->LoadImageEx("会話吹き出しまとめ.png", EX_OTHER_BALLOON, TEX_SIZE_1024);
	//ステージ
	image->LoadImageEx("シオンステージ-1.png", 24, TEX_SIZE_1024);
	image->LoadImageEx("コウネステージ-1.png", 25, TEX_SIZE_1024);
	image->LoadImageEx("研究所背景.png", 26, TEX_SIZE_1024);
	image->LoadImageEx("T字路右側.png", 28, TEX_SIZE_1024);
	image->LoadImageEx("T字路左側.png", 29, TEX_SIZE_1024);

	//チュートリアルステージ------------------------
	image->LoadImageEx("StageTutorial.png", EX_STAGE_TUTORIAL, TEX_SIZE_1024);
	//----------------------------------------------

	//サウンド読み込み↓---------------------------------------------------------------------------
	//チュートリアルステージ
	audio->LoadAudio(0, "Sound\\チュートリアル\\fanfare3.wav");
	//コウネステージ1
	audio->LoadAudio(1, "Sound\\コウネステージ\\ステージ1\\犬\\Tinydog.wav");
	audio->LoadAudio(2, "Sound\\コウネステージ\\ステージ1\\工事音\\Construction.wav");
	//コウネステージ2
	audio->LoadAudio(3, "Sound\\コウネステージ\\ステージ2\\窓ガラスが割れる音\\glass-break.wav");
	audio->LoadAudio(4, "Sound\\コウネステージ\\ステージ2\\Homerun.wav");
	//コウネステージ3
	audio->LoadAudio(5, "Sound\\コウネステージ\\ステージ3\\cicada.wav");
	audio->LoadAudio(6, "Sound\\コウネステージ\\ステージ3\\kitty.wav");
	//コウネステージ4
	audio->LoadAudio(7, "Sound\\コウネステージ\\ステージ4\\Kick the can.wav");
	audio->LoadAudio(8, "Sound\\コウネステージ\\ステージ4\\sunset chime.mp3");
	//コウネステージ5
	audio->LoadAudio(9, "Sound\\コウネステージ\\ステージ5\\Mechanical sound A.wav");
	audio->LoadAudio(10, "Sound\\コウネステージ\\ステージ5\\Mechanical sound B.wav");
	audio->LoadAudio(11, "Sound\\コウネステージ\\ステージ5\\Sax.wav");
	audio->LoadAudio(12, "Sound\\コウネステージ\\ステージ5\\Sax_1.wav");
	audio->LoadAudio(13, "Sound\\コウネステージ\\ステージ5\\Sax_2.wav");
	audio->LoadAudio(14, "Sound\\コウネステージ\\ステージ5\\Sax_3.wav");
	//シオンステージ1
	audio->LoadAudio(15, "Sound\\シオンステージ\\ステージ1\\インターホン\\door_chime.wav");
	audio->LoadAudio(16, "Sound\\シオンステージ\\ステージ1\\犬\\dog.wav");
	audio->LoadAudio(17, "Sound\\シオンステージ\\ステージ1\\鳥\\bard.wav");
	//シオンステージ2
	audio->LoadAudio(18, "Sound\\シオンステージ\\ステージ2\\自転車（ベル）\\Bicycle bell.wav");
	audio->LoadAudio(19, "Sound\\シオンステージ\\ステージ2\\消防車（サイレン）\\Fire engine.wav");
	audio->LoadAudio(20, "Sound\\シオンステージ\\ステージ2\\猫\\cat1.wav");
	//シオンステージ3
	audio->LoadAudio(21, "Sound\\シオンステージ\\ステージ3\\九官鳥\\聖歌２.wav");
	audio->LoadAudio(22, "Sound\\シオンステージ\\ステージ3\\袋\\bag.wav");
	audio->LoadAudio(23, "Sound\\シオンステージ\\ステージ3\\風鈴\\Wind chimes.wav");
	//シオンステージ4
	audio->LoadAudio(24, "Sound\\シオンステージ\\ステージ3\\bike.wav");
	//メルエムステージ1
	audio->LoadAudio(25, "Sound\\メルエムステージ\\ステージ3\\解除音(ドア)\\Release.wav");
	audio->LoadAudio(26, "Sound\\メルエムステージ\\ステージ3\\銃声\\gun.wav");
	audio->LoadAudio(27, "Sound\\メルエムステージ\\ステージ3\\電磁レンジ(ピー)\\microwave.wav");
	//スタート音
	audio->LoadAudio(28, "Sound\\スタート音（はじめからのボタン）\\start4.wav");
	//会話音
	audio->LoadAudio(29, "Sound\\会話音\\select01.wav");
	//決定音
	audio->LoadAudio(30, "Sound\\決定音\\button5.wav");
	//失敗音
	audio->LoadAudio(31, "Sound\\決定音\\キャンセル音\\Cancel.wav");
	//サウンド読み込み↑---------------------------------------------------------------------------

	//透過・暗転初期化
	m_fDefColor[0] = 1.0f;
	m_fDefColor[1] = 1.0f;
	m_fDefColor[2] = 1.0f;
	m_fDefColor[3] = m_fAlpha;

	m_fBackColor[0] = 1.0f;
	m_fBackColor[1] = 1.0f;
	m_fBackColor[2] = 1.0f;
	m_fBackColor[3] = m_fAlpha;

	m_fLeftColor[0] = 0.5f;
	m_fLeftColor[1] = 0.5f;
	m_fLeftColor[2] = 0.5f;
	m_fLeftColor[3] = m_fAlpha;

	m_fRightColor[0] = 0.5f;
	m_fRightColor[1] = 0.5f;
	m_fRightColor[2] = 0.5f;
	m_fRightColor[3] = m_fAlpha;

	m_fWaitColor[0] = 1.0f;
	m_fWaitColor[1] = 1.0f;
	m_fWaitColor[2] = 1.0f;
	m_fWaitColor[3] = m_fWaitAlpha;

	m_fBallonColor[0] = 1.0f;
	m_fBallonColor[1] = 1.0f;
	m_fBallonColor[2] = 1.0f;
	m_fBallonColor[3] = m_fAlpha;

	////吹き出しsrc設定(切り取り）
	//m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].top = 200;
	//m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].left = 0;
	//m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].bottom = 400;
	//m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].right = 600;

	//m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].top = 0;
	//m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].left = 0;
	//m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].bottom = 200;
	//m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].right = 600;

	//m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].top = 400;
	//m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].left = 0;
	//m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].bottom = 600;
	//m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].right = 600;

	//m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].top = 600;
	//m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].left = 0;
	//m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].bottom = 800;
	//m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].right = 600;

	//m_RBalloon_src[TALKBALLOON_SQUARE].top = 800;
	//m_RBalloon_src[TALKBALLOON_SQUARE].left = 0;
	//m_RBalloon_src[TALKBALLOON_SQUARE].bottom = 1000;
	//m_RBalloon_src[TALKBALLOON_SQUARE].right = 600;

	////吹き出しdst設定(貼り付け)
	//m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].top = WINDOW_SIZE_H - 200;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].left = 100;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].bottom = m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].top + 200;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].right = m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].left + 600;

	//m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].top = WINDOW_SIZE_H - 210;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].left = 125;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].bottom = m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].top + 200;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].right = m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].left + 600;

	//m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].top = WINDOW_SIZE_H - 225;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].left = 125;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].bottom = m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].top + 200;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].right = m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].left + 600;

	//m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].top = WINDOW_SIZE_H - 225;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].left = 125;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].bottom = m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].top + 200;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].right = m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].left + 600;

	//m_RBalloon_dst[TALKBALLOON_SQUARE].top = 800;
	//m_RBalloon_dst[TALKBALLOON_SQUARE].left = 0;
	//m_RBalloon_dst[TALKBALLOON_SQUARE].bottom = 1000;
	//m_RBalloon_dst[TALKBALLOON_SQUARE].right = 600;

	//暗転判断用char初期化
	memset(m_cLeftCharaName, '\0', sizeof(char) * 64);
	memset(m_cRightCharaName, '\0', sizeof(char) * 64);
}

void COverlay::Action()
{

	//-------フェードイン---------
	//フェードイン
	if (m_iFadeFlg == 1) {
		if (m_fAlpha >= 0.0f) {
			m_fAlpha += 0.01f;
		}

		if (m_fAlpha > 1.0f) {
			m_iFadeFlg = 0;
			m_fAlpha = 1.0f;
		}

	}
	//フェードアウト
	else if (m_iFadeFlg == 2) {
		if (m_fAlpha >= 0.0f) {
			m_fAlpha -= 0.01f;
		}

		if (m_fAlpha < 0.0f) {
			StopDraw();
			m_iFadeFlg = 0;
			m_iDrawFlg = 0;
			m_bDrawing = false;
			m_fAlpha = 0.0f;
			m_iDrawingCT = 30;
		}
	}
	//------------------------------

	//会話シーン処理開始
	if (m_iDrawFlg == 1) {
		//各キャラクターのテキストデータを一つのポインターで統括
		vector<vector<string>>* m_Chara_Text;
		switch (m_iDrawingStage)
		{
		case STAGE_TYPE::TUTORIAL:
			m_Chara_Text = &textmgr->m_Tutorial_Text;
			break;
		case STAGE_TYPE::SION:
			m_Chara_Text = &textmgr->m_Sion_Text;
			break;
		case STAGE_TYPE::KOUNE:
			m_Chara_Text = &textmgr->m_Koune_Text;
			break;
		case STAGE_TYPE::MERUERU:
			m_Chara_Text = &textmgr->m_Merueru_Text;
			break;
		}

		char linec[32];
		sprintf_s(linec, "%d", m_iChar_Line);
		if (textmgr->isCtrlLine(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line) && !m_bCharaChangeFlg) {
			//string tmpsearch;
			//名前と表情がある場合、文字描画をリセット
			char *namet = textmgr->GetCharaName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
			char *expt = textmgr->GetCharaExp(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
			m_strTemp.clear();
			m_strTemp.resize((*m_Chara_Text)[m_iDrawingStageID].size());
			m_strTempName.clear();
			m_strTempName += namet;
			m_bCharaChangeFlg = true;
			m_iCurrentLine = m_iChar_Line;

			m_tmpsearch = expt;

			if (m_tmpsearch.find("内心") != -1) {
				m_iCurrentBalloon = TALKBALLOON_CLOUD;
			}
			else {
				m_iCurrentBalloon = TALKBALLOON_NORMAL;
			}
			/*
			if (!strlen(m_cLeftCharaName)) {
			strcpy_s(m_cLeftCharaName, namet);
			m_fLeftColor[0] = 1.0f;
			m_fLeftColor[1] = 1.0f;
			m_fLeftColor[2] = 1.0f;
			m_fRightColor[0] = 0.5f;
			m_fRightColor[1] = 0.5f;
			m_fRightColor[2] = 0.5f;

			if (m_tmpsearch.find("内心") != -1) {
			m_iCurrentBalloon = TALKBALLOON_CLOUD;
			}
			else {
			m_iCurrentBalloon = TALKBALLOON_NORMAL;
			}
			}
			else if (!strlen(m_cRightCharaName) && strcmp(m_cLeftCharaName, namet)) {
			strcpy_s(m_cRightCharaName, namet);
			m_fLeftColor[0] = 0.5f;
			m_fLeftColor[1] = 0.5f;
			m_fLeftColor[2] = 0.5f;
			m_fRightColor[0] = 1.0f;
			m_fRightColor[1] = 1.0f;
			m_fRightColor[2] = 1.0f;
			if (m_tmpsearch.find("内心") != -1) {
			m_iCurrentBalloon = TALKBALLOON_CLOUD_RIGHT;
			}
			else {
			m_iCurrentBalloon = TALKBALLOON_NORMAL_RIGHT;
			}
			}

			if (!strcmp(m_cLeftCharaName, namet) && strcmp(m_cRightCharaName, namet)) {
			m_fLeftColor[0] = 1.0f;
			m_fLeftColor[1] = 1.0f;
			m_fLeftColor[2] = 1.0f;
			m_fRightColor[0] = 0.5f;
			m_fRightColor[1] = 0.5f;
			m_fRightColor[2] = 0.5f;
			if (m_tmpsearch.find("内心") != -1) {
			m_iCurrentBalloon = TALKBALLOON_CLOUD_LEFT;
			}
			else {
			m_iCurrentBalloon = TALKBALLOON_NORMAL_LEFT;
			}
			}
			else if (strcmp(m_cLeftCharaName, namet) && !strcmp(m_cRightCharaName, namet)) {
			m_fLeftColor[0] = 0.5f;
			m_fLeftColor[1] = 0.5f;
			m_fLeftColor[2] = 0.5f;
			m_fRightColor[0] = 1.0f;
			m_fRightColor[1] = 1.0f;
			m_fRightColor[2] = 1.0f;
			if (m_tmpsearch.find("内心") != -1) {
			m_iCurrentBalloon = TALKBALLOON_CLOUD_RIGHT;
			}
			else {
			m_iCurrentBalloon = TALKBALLOON_NORMAL_RIGHT;
			}
			}*/

			delete namet;
			delete expt;
		}

		//------------------------テキスト処理開始---------------------------
		if (m_fAlpha == 1.0f) {
			//全行描画中
			if (m_iChar_Line < (*m_Chara_Text)[m_iDrawingStageID].size()) {
				//文字挿入判定処理
				if (!m_in_str) {
					//この行に文字挿入部分があるか確認
					m_in_str = textmgr->isInStr(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					if (m_in_str) {
						//次ループでこのif判定に入らないように、次の行へ進める
						m_iChar_Line++;

						//挿入テキストを指定している場合
						if (m_piShowTextID) {
							int roop_id;
							//そのアドレスが
							//表示指定アドレスの中（m_piShowTextID）にあるか調べる
							for (roop_id = 0; roop_id < m_iIDSize; roop_id++) {
								if (m_in_str->id == m_piShowTextID[roop_id]) {
									break;
								}
							}

							//↑のループで最後まで調べた結果、
							//表示指定アドレスの中になかった
							if (roop_id == m_iIDSize) {
								//挿入文字を表示しないので、終了行まで飛ばします。
								m_iChar_Line = m_in_str->end_line;
							}

						}
						//挿入テキストを指定していない場合
						else {
							//挿入文字を表示しないので、終了行まで飛ばします。
							m_iChar_Line = m_in_str->end_line;
						}
					}
				}

				//この行に選択肢がある場合、選択肢を生成
				SelectInfo* select = textmgr->isSelect(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
				if (select) {
					//次ループでこのif判定に入らないように、次の行へ進める
					m_iChar_Line++;

					//前回の選択肢が生成されている場合、削除
					SAFE_DELETE(m_select);

					//選択肢生成
					m_select = new CSelect(select);
				}

				//選択肢動作(選択していないとき)
				if (m_select && m_select->GetSelectNum() == -1) {
					//選択したか確認
					if (m_select->Select()) {

						//選択した項目番号をメンバに保存
						int sel_num = m_select->GetSelectNum();
						char sel_num_str[3];
						sprintf_s(sel_num_str, "%d-", sel_num + 1);
						m_SelectNum += sel_num_str;

						//選択した場所へ飛ぶ
						m_iChar_Line = m_select->GetInfo()->menu[m_select->GetSelectNum()].child_text_line;

						//次のテキストをセットする命令発信
						NextTextSet();
					}
				}
				//テキスト描画中
				else {
					//文字挿入部分を発見後
					if (m_in_str) {
						//挿入文字の終了行に到達
						if (m_in_str->end_line == m_iChar_Line) {
							//文字挿入データへの参照を切る
							m_in_str = NULL;

							//次のテキストをセットする命令発信
							NextTextSet();
						}
					}

					//選択肢を選択した後に入ります
					if (m_select) {
						//その選択した項目の終了行なら
						if (m_select->GetEndLine() == m_iChar_Line) {
							//選択肢オブジェクト破棄
							SAFE_DELETE(m_select);

							//会話終了
							DrawTextEnd();

							//Action関数終了
							return;
						}
					}

					//待ち時間カウント後、１文字描画
					m_iDelay++;

					//その行の文字描画中
					if (m_iChar_Pos < (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line].length()) {
						//マウスクリックすると１行一括表示
						if (input->GetMouButtonLOnce()) {
							m_strTemp[m_iChar_Line].clear();
							m_strTemp[m_iChar_Line] += (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line];
							m_iChar_Pos = (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line].length() + 1;
						}
						else {
							if (m_iDelay > m_iTextSpeed) {
								//何バイトの文字か確認
								/*unsigned char lead = (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line][m_iChar_Pos];
								if (lead < 128) {
								m_iChar_Size = 1;
								}
								else if (lead < 224) {
								m_iChar_Size = 2;
								}
								else if (lead < 240) {
								m_iChar_Size = 3;
								}
								else {
								m_iChar_Size = 4;
								}*/

								//【応急処置】
								//１文字取得
								char lead = (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line][m_iChar_Pos];

								//先行バイトなら
								if (IsDBCSLeadByte(lead)) {
									m_iChar_Size = 2;//2バイト文字
								}
								//先行バイトでなければ
								else {
									m_iChar_Size = 1;//1バイト文字
								}
								char c[8];
								sprintf_s(c, "%s", (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line].substr(m_iChar_Pos, m_iChar_Size).c_str());
								m_strTemp[m_iChar_Line] += c;

								m_iChar_Pos += m_iChar_Size;
							}
						}
					}
					//一行描画終了
					else {
						if (input->GetMouButtonLOnce()) {
							//次のテキストをセットする命令発信
							NextTextSet();
						}
						else {
							if (m_iDelay > m_iTextSpeed) {
								if (!m_bNextWaiting) {
									m_fWaitAlpha = 1.0f;
									m_bNextWaiting = true;
								}
								else {
									m_fWaitAlpha = 0.0f;
									m_bNextWaiting = false;
								}
							}
						}
					}
				}
			}
			//全テキスト描画終了
			else {
				if (input->GetMouButtonL()) {
					//会話終了
					DrawTextEnd();

					//Action関数終了
					return;
				}
				else {
					if (m_iDelay > m_iTextSpeed) {
						if (!m_bNextWaiting) {
							m_fWaitAlpha = 1.0f;
							m_bNextWaiting = true;
						}
						else {
							m_fWaitAlpha = 0.0f;
							m_bNextWaiting = false;
						}
					}
				}
			}

			if (m_iDelay > m_iTextSpeed)
				m_iDelay = 0;
			//【※テキスト描画は下に移動させました。】
		}
		//------------------------テキスト処理終了---------------------------
	}
}

void COverlay::Draw()
{
	/*
	//test overlay
	if (m_iDrawFlg == 0) {
	RECT src, dst;

	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };

	//切り取り座標
	dst.top = 0;
	dst.left = 0;
	dst.bottom = dst.top + 512;
	dst.right = dst.left + 512;

	//転送先座標
	src.top = m_y;
	src.left = m_x;
	src.bottom = src.top + 600;
	src.right = src.left + 800;

	image->DrawEx(0, &src, &dst, col, 0.0f);
	}
	*/

	//talk overlay
	if (m_iDrawFlg == 1) {

		char tmp[128];
		char tmpname[64] = { 0 };



		////-------------------背景------------------------
		//RECT backsrc, backdst;
		//m_fBackColor[3] = m_fAlpha;
		////切り取り座標
		//backdst.top = 0;
		//backdst.left = 0;
		//backdst.bottom = backdst.top + 512;
		//backdst.right = backdst.left + 512;

		////転送先座標
		//backsrc.top = 0;
		//backsrc.left = 0;
		//backsrc.bottom = backsrc.top + 600;
		//backsrc.right = backsrc.left + 800;

		//image->DrawEx(61, &backsrc, &backdst, m_fBackColor, 0.0f);
		////-------------------背景終------------------------



		////------------------------キャラビジュアル表示処理---------------------------
		//int talk_chara = 0;	  //現在発言中のキャラ
		//					  //int talk_chara_dir=0; //現在発言中の方向

		//float col[4] = { 1.0f,1.0f ,1.0f ,m_fAlpha };
		//TalkCharaData* talk_data;

		//for (int dir = 0; dir < TALK_CHARA_DIR_MAX; dir++) {
		//	//末尾からループ
		//	for (int chara = TALK_CHARA_ONE_DIR_MAX - 1; chara >= 0; chara--) {

		//		talk_data = &textmgr->m_talk_chara_list[dir][chara];

		//		//キャラクターが格納されていないならスキップ
		//		if (talk_data->name.size() == 0) {
		//			continue;
		//		}

		//		//初回の表情代入
		//		if (m_talk_expression_list[dir][chara].size() == 0) {
		//			m_talk_expression_list[dir][chara] = talk_data->expression;
		//		}

		//		//挿入処理
		//		if (talk_data->in_shift_id != -1) {
		//			//挿入キャラを指定している場合
		//			if (m_piShowCharaID) {
		//				int roop_id;
		//				//そのアドレスが
		//				//表示指定アドレスの中（m_piShowCharaID）にあるか調べる
		//				for (roop_id = 0; roop_id < m_iCharaIDSize; roop_id++) {
		//					if (talk_data->in_shift_id == m_piShowCharaID[roop_id]) {
		//						break;
		//					}
		//				}

		//				//↑のループで最後まで調べた結果、
		//				//表示指定アドレスの中になかった
		//				if (roop_id == m_iIDSize) {
		//					//このキャラは表示しない
		//					continue;
		//				}

		//			}
		//			else {
		//				//このキャラは表示しない
		//				continue;
		//			}
		//		}

		//		//現在発言中のキャラなら、スキップ
		//		if (talk_data->name.find(m_strTempName.c_str()) != -1) {
		//			//キャラ番号と方向を保存
		//			talk_chara = chara;
		//			m_iNowDrawDir = dir;

		//			//初回の方向を登録
		//			if (m_iBeforeDrawDir == -1) {
		//				m_iBeforeDrawDir = dir;
		//			}
		//			//表情更新
		//			m_talk_expression_list[dir][chara] = m_tmpsearch;
		//			continue;
		//		}
		//		//現在発言中のキャラでなければ、暗くする
		//		else {
		//			col[0] = 0.5f;
		//			col[1] = 0.5f;
		//			col[2] = 0.5f;
		//		}

		//		//キャラクター描画
		//		DrawCharacter(talk_data->name.c_str(), m_talk_expression_list[dir][chara].c_str(), dir, chara, col);
		//	}
		//}

		////現在発言中のキャラ描画-----------------------------
		//col[0] = 1.0f;
		//col[1] = 1.0f;
		//col[2] = 1.0f;
		//talk_data = &textmgr->m_talk_chara_list[m_iNowDrawDir][talk_chara];
		//DrawCharacter(talk_data->name.c_str(), m_talk_expression_list[m_iNowDrawDir][talk_chara].c_str(), m_iNowDrawDir, talk_chara, col);
		////---------------------------------------------------

		//////-------------------左キャラ----------------------
		////RECT leftsrc, leftdst;
		////m_fLeftColor[3] = m_fAlpha;
		//////切り取り座標
		////leftdst.top = 0;
		////leftdst.left = 0;
		////leftdst.bottom = leftdst.top + 350;
		////leftdst.right = leftdst.left + 200;

		//////転送先座標
		////leftsrc.top = TALK_CHARA_LEFT_MARGIN_Y;
		////leftsrc.left = 0;
		////leftsrc.bottom = leftsrc.top + 300;
		////leftsrc.right = leftsrc.left + 250;

		////image->DrawEx(m_iLeftCharaImageID, &leftsrc, &leftdst, m_fLeftColor, 0.0f);
		//////-------------------左キャラ終---------------------

		//////-------------------右キャラ----------------------
		////RECT rightsrc, rightdst;
		////m_fRightColor[3] = m_fAlpha;
		//////切り取り座標
		////rightdst.top = 70;
		////rightdst.left = 380;
		////rightdst.bottom = rightdst.top + 235;
		////rightdst.right = rightdst.left + 274;

		//////転送先座標
		////rightsrc.top = TALK_CHARA_RIGHT_MARGIN_Y;
		////rightsrc.left = WINDOW_SIZE_W - TALK_CHARA_RIGHT_MARGIN_X;
		////rightsrc.bottom = rightsrc.top + 300;
		////rightsrc.right = rightsrc.left + 300;

		////image->DrawEx(m_iRightCharaImageID, &rightsrc, &rightdst, m_fRightColor, 0.0f);
		//////-------------------右キャラ終---------------------

		////-------------------中キャラ----------------------
		///*
		//RECT centersrc, centerdst;
		//m_fCenterColor[3] = m_fAlpha;
		////切り取り座標
		//centerdst.top = 0;
		//centerdst.left = 0;
		//centerdst.bottom = centerdst.top + 350;
		//centerdst.right = centerdst.left + 200;

		////転送先座標
		//centersrc.top = TALK_CHARA_LEFT_MARGIN_Y;
		//centersrc.left = WINDOW_SIZE_W/2-100;
		//centersrc.bottom = centersrc.top + 300;
		//centersrc.right = centersrc.left + 250;

		//image->DrawEx(62, &centersrc, &centerdst, col, 0.0f);
		//*/
		////-------------------中キャラ終---------------------
		////------------------------キャラビジュアル表示処理終了---------------------------


		//-------------------吹き出し-----------------------
		for (int frame = 0; frame < 2; frame++) {


			m_fBallonColor[3] = m_fAlpha;

			//切り取り座標
			m_dst.top = m_iCurrentBalloon * 165;
			m_dst.left = 0;
			m_dst.right = m_dst.left + 310;
			m_dst.bottom = m_dst.top + 165;

			//転送先座標左上
			m_src.top = WINDOW_SIZE_H - 250;
			m_src.left = 100;

			int dir;//前回の吹き出しと今回の吹き出し分岐用

					//前回の吹き出し
			if (frame == 0) {
				dir = m_iBeforeDrawDir;

				//暗い
				m_fBallonColor[0] = 0.5f;
				m_fBallonColor[1] = 0.5f;
				m_fBallonColor[2] = 0.5f;
			}
			//今回の吹き出し
			else {
				dir = m_iNowDrawDir;
				//明るい
				m_fBallonColor[0] = 1.0f;
				m_fBallonColor[1] = 1.0f;
				m_fBallonColor[2] = 1.0f;
			}

			//右なら左右反転
			if (dir == CHARA_RIGHT) {
				int left = m_dst.left;
				m_dst.left = m_dst.right;
				m_dst.right = left;

				//表示位置を少しずらす
				m_src.left += 10.0f;
				m_src.top -= 10.0f;
			}

			//転送先座標右下
			m_src.right = m_src.left + 600;
			m_src.bottom = m_src.top + 280;

			image->DrawEx(EX_OTHER_BALLOON, &m_src, &m_dst, m_fBallonColor, 0.0f);
		}
		//-------------------吹き出し終--------------------

		//-------------------待機インジケータ---------------
		RECT waitsrc, waitdst;
		m_fWaitColor[3] = m_fWaitAlpha;
		//切り取り座標
		waitdst.top = 0;
		waitdst.left = 0;
		waitdst.bottom = waitdst.top + 256;
		waitdst.right = waitdst.left + 256;
		//転送先座標
		waitsrc.top = WINDOW_SIZE_H - 100;
		waitsrc.left = WINDOW_SIZE_W - 250;
		waitsrc.bottom = waitsrc.top + 64;
		waitsrc.right = waitsrc.left + 96;

		image->DrawEx(63, &waitsrc, &waitdst, m_fWaitColor, 0.0f);
		//-------------------待機インジケータ終-------------

		//-------------------------------テキスト表示処理------------------------------------
		//テキスト描画開始しているか確認
		if (m_fAlpha == 1.0f) {
			sprintf_s(tmpname, "%s", m_strTempName.c_str());
			float col[4] = { 0.0f,0.0f,0.0f,m_fAlpha };
			font->StrDraw(tmpname, m_src.left + 50, m_src.top + 50, 20, col);

			for (unsigned int i = 0; i < m_strTemp.size(); ++i) {
				sprintf_s(tmp, "%s", m_strTemp[i].c_str());
				float col[4] = { 0.0f,0.0f,0.0f,m_fAlpha };
				font->StrDraw(tmp, m_src.left + 50, (m_src.top + 80) + ((i - m_iCurrentLine) * 20), 20, col);
			}
		}
		//-------------------------------テキスト表示処理終了--------------------------------
	}
}

//キャラクター描画
//引数：
//name			=キャラクター名
//expression	=表情
//dir			=位置（左か右）
//dir_count		=dirの方向の位置番号
//col			=描画する色RGBA
void COverlay::DrawCharacter(const char* name, const char* expression, int dir, int dir_count, float col[4]) {
	RECT leftsrc, leftdst;

	int image_id = 58;

	//切り取り座標
	leftdst.top = 192;
	leftdst.left = 0;
	leftdst.bottom = leftdst.top + 64;
	leftdst.right = leftdst.left + 64;

	//表示X座標決定
	if (dir == CHARA_LEFT) {
		leftsrc.left = 200 - dir_count * 100;
	}
	else {
		leftsrc.left = 500 + dir_count * 100;
	}

	//転送先座標
	leftsrc.top = 100;
	//leftは↑で決定しています。
	leftsrc.bottom = leftsrc.top + 380;
	leftsrc.right = leftsrc.left + 200;

	image->DrawEx(image_id, &leftsrc, &leftdst, col, 0.0f);

	//キャラクター名表示
	g_DrawFont->StrDraw((char*)name, leftsrc.left, leftsrc.top, 32, col);

	//表情表示
	g_DrawFont->StrDraw((char*)expression, leftsrc.left, leftsrc.top + 32, 32, col);
}

//トークの描画有効
//引数：
//stage				=キャラクター（COverlay.hの enum STAGE_TYPEの中から指定）
//stageID			=メッセージ番号（COverlay.hの enum tutorial , enum koune , enum sion , enum merueruの中から選択）
//piShowTextID		=挿入文字の中から表示するものを指定するアドレス
//size				=↑のデータ個数（main.hのマクロ関数「SIZE()」を使用してください。）
//piShowCharaID		=挿入キャラクターの中から表示するものを指定するアドレス
//show_chara_id_size=↑のデータ個数（main.hのマクロ関数「SIZE()」を使用してください。）
void COverlay::talkDraw(int stage, int stageID, int* piShowTextID, int size, int* piShowCharaID, int show_chara_id_size)
{
	/*if (m_iDrawingCT > 0) {
	m_iDrawingCT--;
	return;
	}*/

	//スタンバイするまで次のメッセージを描画しない
	if (!m_bNextFlg) return;

	//表示テキスト指定アドレスをセット----------------
	//（各メッセージ呼び出し時、初回のみ）
	if (!m_piShowTextID) {
		if (piShowTextID && size > 0) {
			//メモリ生成
			m_piShowTextID = new int[size];

			//保存
			for (int id = 0; id < size; id++) {
				m_piShowTextID[id] = piShowTextID[id];
			}
			//サイズを保存
			m_iIDSize = size;
		}
		else {
			m_piShowTextID = NULL;
		}
	}
	//------------------------------------------------

	//表示キャラクター指定アドレスをセット------------
	//（各メッセージ呼び出し時、初回のみ）
	if (!m_piShowCharaID) {
		if (piShowCharaID && show_chara_id_size > 0) {
			//メモリ生成
			m_piShowCharaID = new int[show_chara_id_size];

			//保存
			for (int id = 0; id < show_chara_id_size; id++) {
				m_piShowCharaID[id] = piShowCharaID[id];
			}
			//サイズを保存
			m_iIDSize = show_chara_id_size;
		}
		else {
			m_piShowCharaID = NULL;
		}
	}
	//------------------------------------------------

	if (m_iDrawingStage == stage && m_iDrawingStageID == stageID && m_fAlpha != 0.0f)
		return;

	if (m_fAlpha == 0.0f)
		FadeIn();
	m_iDrawFlg = 1;
	m_bDrawing = true;
	m_bNextFlg = false;//次のメッセージをスタンバイするまで待つ
	m_iDrawingStage = stage;
	m_iDrawingStageID = stageID;
	m_iDrawingStageIDGet = stageID;
	m_strTempName.resize(32);

	switch (stage)
	{
	case STAGE_TYPE::TUTORIAL:
		m_strTemp.resize(textmgr->m_Tutorial_Text[m_iDrawingStageID].size());
		break;
	case STAGE_TYPE::SION:
		m_strTemp.resize(textmgr->m_Sion_Text[m_iDrawingStageID].size());
		break;
	case STAGE_TYPE::KOUNE:
		m_strTemp.resize(textmgr->m_Koune_Text[m_iDrawingStageID].size());
		break;
	case STAGE_TYPE::MERUERU:
		m_strTemp.resize(textmgr->m_Merueru_Text[m_iDrawingStageID].size());
		break;
	}
}

//次のメッセージを描画するまでスタンバイ
//戻り値：
//次のメッセージへ進める状態ならtrueを返す
bool COverlay::NextWait() {
	//描画終了時
	if (!m_bDrawing) {
		//次のメッセージに移行するフラグを立てる
		m_bNextFlg = true;

		//表示テキスト指定アドレスを破棄
		SAFE_DELETE_ARRAY(m_piShowTextID);

		//表示キャラ指定アドレスを破棄
		SAFE_DELETE_ARRAY(m_piShowCharaID);

		return true;
	}
	return false;
}

void COverlay::StopDraw() {
	if (m_iDrawFlg == 1) {
		m_iChar_Pos = 0;
		m_iChar_Size = 0;
		m_iChar_Line = 0;
		m_iDelay = 0;
		m_iCurrentLine = 0;

		m_bCharaChangeFlg = false;
		m_strTemp.clear();
		m_strTempName.clear();
		m_iDrawingStage = -1;
		m_iDrawingStageID = -1;
		memset(m_cLeftCharaName, '\0', sizeof(m_cLeftCharaName));
		memset(m_cRightCharaName, '\0', sizeof(m_cRightCharaName));

		m_fLeftColor[0] = 0.5f;
		m_fLeftColor[1] = 0.5f;
		m_fLeftColor[2] = 0.5f;
		m_fLeftColor[3] = m_fAlpha;

		m_fRightColor[0] = 0.5f;
		m_fRightColor[1] = 0.5f;
		m_fRightColor[2] = 0.5f;
		m_fRightColor[3] = m_fAlpha;

		//表情バッファクリア
		for (int dir = 0; dir < TALK_CHARA_DIR_MAX; dir++) {
			//末尾からループ
			for (int chara = 0; chara < TALK_CHARA_ONE_DIR_MAX; chara++) {
				m_talk_expression_list[dir][chara].clear();
			}
		}

		//キャラクター方向初期化
		m_iBeforeDrawDir = -1;
		m_iNowDrawDir = -1;
	}
}

void COverlay::FadeIn()
{
	m_iFadeFlg = 1;
}

void COverlay::FadeOut()
{
	m_iFadeFlg = 2;
}

//次のテキストをセットする命令発信
void COverlay::NextTextSet() {
	m_iChar_Pos = 0;
	m_iChar_Line++;
	m_fWaitAlpha = 0.0f;
	m_bNextWaiting = false;
	m_bCharaChangeFlg = false;

	//今回のキャラクター表示方向を保存
	m_iBeforeDrawDir = m_iNowDrawDir;
}

//特定の選択項目を選択したか確認
//引数：
//select=調べる選択項目（例：1番目の項目を選んでから2番目の項目を選んだ→"1-2"）
//戻り値：
//引数指定した選択項目が選ばれていたらtrue、選ばれていなかったらfalseを返す
bool COverlay::Selected(const char* select) {
	if (m_SelectNum.find(select) != -1) {
		return true;
	}
	return false;
}