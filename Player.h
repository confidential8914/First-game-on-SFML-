
class PLAYER
{
private:
	
	#define VFrame 7
	#define DFrame 7
	
	int SizeX;
	int SizeY;
	
	Texture TPlayer;

	float time;
	
	float NumberFrame;	
	float NumberDownFrame;
	
	char OldVector;
	
	bool onGround;
	
public:
	
	PLAYER();
	
	~PLAYER();

public:
	
	float Speed;
	
	Sprite sprite;
	
private:
	
	void Gravity();
	
public:
	
	void Update(float time);
	
	void Control();
};
