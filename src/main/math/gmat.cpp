#include "gmat.h"


template <class T> struct gmat<T> gmat_add(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] + b[row][col];
	}
	return  c;
}

template <class T> struct gmat<T> gmat_sub(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] - b[row][col];
	}
	return  c;
}

template <class T> struct gmat<T> gmat_add(struct gmat<T> a, T b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] + b;
	}
	return  c;
}

template <class T> struct gmat<T> gmat_sub(struct gmat<T> a, T b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] - b;
	}
	return  c;
}

template <class T> struct gmat<T> gmat_mult(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));

		// Initialize position on c and loop through a's row size.
		c.num_arr[row][col] = 0;
		for (int n = 0; n < sizeof(a.num_arr) / sizeof(a.num_arr[0]); n++) 
			c.num_arr[row][col] += a.num_arr[row][n] * b.num_arr[n][col];
	}
	return  c;
}

template <class T> struct gvec<T> gmat_mult(struct gvec<T> a, struct gmat<T> b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(T); i++)
	{
		c.num_arr[i] = 0;
		for (int n = 0; n < sizeof(a.num_arr) / sizeof(T); n++)
			c.num_arr[i] += a.num_arr[n] * b.num_arr[n][i];
	}
	return c;
}

template <class T> struct gvec<T> gmat_mult(struct gmat<T> a, struct gvec<T> b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(T); i++)
	{
		c.num_arr[i] = 0;
		for (int n = 0; n < sizeof(b.num_arr) / sizeof(T); n++)
			c.num_arr[i] += a.num_arr[i][n] * b.num_arr[n]; 
	}
	return c;
}

template <class T> struct gmat<T> gmat_bemult(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] * b.num_arr[row][col];
	}
	return  c;
}
