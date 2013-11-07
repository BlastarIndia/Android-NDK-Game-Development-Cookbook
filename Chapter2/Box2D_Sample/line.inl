void set_pixel(unsigned char* fb, int w, int h, int x, int y, int color)
{
	if(x < 0 || y < 0 || x > w - 1 || y > h - 1) { return; }

	fb[((h - 1 - y) * w + x) * 3 + 0] = ( color       ) & 0xFF;
	fb[((h - 1 - y) * w + x) * 3 + 1] = ( color >> 8  ) & 0xFF;
	fb[((h - 1 - y) * w + x) * 3 + 2] = ( color >> 16 ) & 0xFF;
}

void swap_int(int& v1, int& v2) { int t = v1; v1 = v2; v2 = t; }

void line_bresenham(unsigned char* fb, int w, int h, int p1x, int p1y, int p2x, int p2y, int color)
{
	int F, x, y;

	if (p1x > p2x)  // Swap points if p1 is on the right of p2
	{
		swap_int(p1x, p2x);
		swap_int(p1y, p2y);
	}

	// Handle trivial cases separately for algorithm speed up.
	// Trivial case 1: m = +/-INF (Vertical line)
	if (p1x == p2x)
	{
		// Swap y-coordinates if p1 is above p2
		if (p1y > p2y) { swap_int(p1y, p2y); }

		x = p1x;
		y = p1y;
		while (y <= p2y)
		{
			set_pixel(fb, w, h, x, y, color);
			y++;
		}
		return;
	}
	// Trivial case 2: m = 0 (Horizontal line)
	else if (p1y == p2y)
	{
		x = p1x;
		y = p1y;

		while (x <= p2x)
		{
			set_pixel(fb, w, h, x, y, color);
			x++;
		}
		return;
	}

	int dy            = p2y - p1y;  // y-increment from p1 to p2
	int dx            = p2x - p1x;  // x-increment from p1 to p2
	int dy2           = (dy << 1);  // dy << 1 == 2*dy
	int dx2           = (dx << 1);
	int dy2_minus_dx2 = dy2 - dx2;  // precompute constant for speed up
	int dy2_plus_dx2  = dy2 + dx2;

	if (dy >= 0)    // m >= 0
	{
		// Case 1: 0 <= m <= 1 (Original case)
		if (dy <= dx)   
		{
			F = dy2 - dx;    // initial F

			x = p1x;
			y = p1y;
			while (x <= p2x)
			{
				set_pixel(fb, w, h, x, y, color);
				if (F <= 0)
				{
					F += dy2;
				}
				else
				{
					y++;
					F += dy2_minus_dx2;
				}
				x++;
			}
		}
		// Case 2: 1 < m < INF (Mirror about y=x line
		// replace all dy by dx and dx by dy)
		else
		{
			F = dx2 - dy;    // initial F

			y = p1y;
			x = p1x;
			while (y <= p2y)
			{
				set_pixel(fb, w, h, x, y, color);
				if (F <= 0)
				{
					F += dx2;
				}
				else
				{
					x++;
					F -= dy2_minus_dx2;
				}
				y++;
			}
		}
	}
	else    // m < 0
	{
		// Case 3: -1 <= m < 0 (Mirror about x-axis, replace all dy by -dy)
		if (dx >= -dy)
		{
			F = -dy2 - dx;    // initial F

			x = p1x;
			y = p1y;
			while (x <= p2x)
			{
				set_pixel(fb, w, h, x, y, color);
				if (F <= 0)
				{
					F -= dy2;
				}
				else
				{
					y--;
					F -= dy2_plus_dx2;
				}
				x++;
			}
		}
		// Case 4: -INF < m < -1 (Mirror about x-axis and mirror 
		// about y=x line, replace all dx by -dy and dy by dx)
		else    
		{
			F = dx2 + dy;    // initial F

			y = p1y;
			x = p1x;
			while (y >= p2y)
			{
				set_pixel(fb, w, h, x, y, color);
				if (F <= 0)
				{
					F += dx2;
				}
				else
				{
					x++;
					F += dy2_plus_dx2;
				}
				y--;
			}
		}
	}
}
