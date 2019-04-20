
class PLAYER
{
private:
	
	#define VFrame 7
	#define DFrame 7
	
	int SizeX;
	int SizeY;
	
	float x;
	float y;
	
	FloatRect rect;
	Texture TPlayer;

	float time;
	
	float NumberFrame;	
	float NumberDownFrame;
	
	float AOG;
										
	char OldVector;
	
	bool onGround;
	
public:
	
	PLAYER();
	
	~PLAYER();

public:
	
	float Speed;
	
	Sprite sprite;
	
private:
	
	void GravityAndMotion();
	
public:
	
	void Update(float time);
	
	void Control();
};
