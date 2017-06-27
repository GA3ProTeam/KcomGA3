#include "../main.h"

bool Gimmick::gimmickCd()
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//Ø‚èŽæ‚èÀ•W
	m_dst.top = 0;						m_dst.left = 0;
	m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	//“]‘—æÀ•W
	m_src.top = inpu;					m_src.left = m_Button_x;
	m_src.bottom = m_src.top + 64;		m_src.right = m_src.left + 64;

	//c‚Æ‰¡(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
	}
}
