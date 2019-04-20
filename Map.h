class MAP
{
private:
	
public:
	
	#define H 12
	#define W 60	
	
	string Map[H];
	string Background[H];
	
	RectangleShape rectangle;
		
public:
	
	MAP();
   ~MAP();
	
private:

public:
	
	void DrawMap();
	void DrawBackground();
};

