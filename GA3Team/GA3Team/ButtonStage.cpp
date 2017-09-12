#include "main.h"

//�C�j�V�����C�Y
void ButtonStage::Init(int x, int y, int w, int h, bool bSelFlg, CObjStageTab* sStage_Tab ,int iStageNumber){
	//�X�e�[�W�ԍ���ݒ�
	m_iStageNumber = iStageNumber;

	//�I���ł��邩�ǂ�����ݒ�
	m_bSelFlg = bSelFlg;

	//�X�e�[�W�^�u�ւ̎Q�Ǝ擾
	m_sStage_Tab = sStage_Tab;

	//�؂�����W�ݒ�
	m_rDst.top = sStage_Tab->GetCharacterNum()*64;
	m_rDst.bottom = m_rDst.top+64;
	m_rDst.left = m_iStageNumber*64;
	m_rDst.right = m_rDst.left+64;

	////�{�^���̃A�N�e�B�u���(����\���ǂ���)������
	//m_bActive=true;

	//�I���ł�����
	if (m_bSelFlg) {
		//�{�^���̐F�𖾂邭
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;
		m_fCol[3] = 1.0f;

	}//�I���ł��Ȃ����
	else {
		//�{�^���̐F���Â�
		m_fCol[0] = 0.5f;
		m_fCol[1] = 0.5f;
		m_fCol[2] = 0.5f;
		m_fCol[3] = 1.0f;
	}

	//�e�N���X��������
	Button::Init(x, y, w, h, false);
}

//�f�X�g���N�^
void ButtonStage::Destructor(){
	
}

//�A�N�V����
void ButtonStage::Action(){
	//�I���ł��Ȃ���ԂȂ�A���삵�Ȃ�
	if (!m_bSelFlg) return;

	//�{�^���������ꂽ���ǂ����m�F
	Push();

	//������Ă���
	if (m_bStatus) {
		//�I�񂾃X�e�[�W�ƃL�����N�^�[�̔ԍ������[�U�[�f�[�^�ɕۑ�
		User()->m_iCurrentStage = m_iStageNumber;
		User()->m_iCurrentChara = m_sStage_Tab->GetCharacterNum();
		//�Q�[���{�҂Ɉړ�
		Manager()->Pop(new CSceneGameMain);
	}
}

//�h���[
void ButtonStage::Draw() {
	//�؂������W
	m_rDst.top = m_sStage_Tab->GetCharacterNum() * 64;
	m_rDst.left = m_iStageNumber * 64;
	m_rDst.bottom = m_rDst.top + 64;
	m_rDst.right = m_rDst.left + 64;

	//�]������W
	m_rSrc.top = m_iYpos;
	m_rSrc.left = m_iXpos;
	m_rSrc.bottom = m_rSrc.top + m_iHeight;
	m_rSrc.right = m_rSrc.left + m_iWidth;
	
	//�`��
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol,0.0f);
}