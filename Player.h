
class PLAYER
{
private:
	
	#define VFrame 7
	#define DFrame 7
	#define AFrame 3
	
	Texture TPlayer;

	float time;
	
	float NumberFrame;	
	float NumberDownFrame;
	float NumberAttackFrame;
	
	float AOG;
										
	char OldVector;
	
	string TypeAttack;
	
public:
	
	PLAYER();
	
	~PLAYER();

public:
	
	int SizeX;
	int SizeY;
	
	float x;
	float y;
	
	bool onGround;
	
	FloatRect rect;
	
	float Speed;
	float SizeJump;
	
	int FloorLevel;
	
	Sprite sprite;
	
private:
	
	void GravityAndMotion();
	void Boundaries();
	
public:
	
	void Attack(string Type);
	
	void Update(float time);
	
	void Control();
};
