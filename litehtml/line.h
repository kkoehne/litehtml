#pragma once

#include "types.h"

namespace litehtml
{
	class line
	{
	public:
		
		typedef std::vector<line>	vector;

	private:
		elements_vector	m_items;
		int				m_height;
		int				m_top_margin;
		int				m_bottom_margin;
		bool			m_is_block;
		int				m_left;
		int				m_top;
		int				m_padding_bottom;
		int				m_padding_top;
		element_clear	m_clear;
		bool			m_last_white_space;
	public:
		line(void)
		{
			m_padding_bottom	= 0;
			m_padding_top		= 0;
			m_height			= 0;
			m_top_margin		= 0;
			m_bottom_margin		= 0;
			m_is_block			= false;
			m_left				= 0;
			m_top				= 0;
			m_last_white_space	= true;
			m_clear				= clear_none;
		}

		line(const line& val)
		{
			m_items				= val.m_items;
			m_height			= val.m_height;
			m_top_margin		= val.m_top_margin;
			m_bottom_margin		= val.m_bottom_margin;
			m_is_block			= val.m_is_block;
			m_left				= val.m_left;
			m_top				= val.m_top;
			m_padding_bottom	= val.m_padding_bottom;
			m_padding_top		= val.m_padding_top;
			m_clear				= val.m_clear;
			m_last_white_space	= val.m_last_white_space;
		}

		~line(void)
		{
			clear();
		}

		void clear()
		{
			m_items.clear();
			m_height			= 0;
			m_top_margin		= 0;
			m_bottom_margin		= 0;
			m_is_block			= false;
			m_left				= 0;
			m_top				= 0;
			m_padding_bottom	= 0;
			m_padding_top		= 0;
			m_clear				= clear_none;
			m_last_white_space	= true;
		}

		void	operator+=(element* el);
		void	set_top(int top, element* parent);
		void	add_top(int add);

		int		get_height() const			{	return m_height;			}
		int		get_left() const			{	return m_left;				}
		void	set_left(int left) 			{	m_left = left;				}
		int		get_top() const				{	return m_top;				}
		int		get_margin_top() const		{	return m_top_margin;		}
		int		get_margin_bottom() const	{	return m_bottom_margin;		}
		bool	is_block() const			{	return m_is_block;			}
		bool	empty()	const				{	return m_items.empty();		}
		bool	is_white_space() const		{	return m_last_white_space;	}
		void	get_elements(elements_vector& els);
		bool	finish();
		bool	collapse_top_margin()		{	return (m_padding_top == 0);	}
		bool	collapse_bottom_margin()	{	return (m_padding_bottom == 0);	}
		
		element_clear get_clear_floats() const { return m_clear; }
	};
}
