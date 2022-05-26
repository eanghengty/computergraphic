class wcPt2D{
	public:
		GLfloat x,y;		
}

inline GLint round(const GLfloata){
return GLint (a+0.5);
}
cosnt Glint winLeftBitCode = 0x1;
const GLint winRightBitCode = 0x2;
const GLint winBottomBitCode = 0x4;
const GLint winTopBitCode = 0x8;

inline GLint inside (GLint code){
return GLint (!code);
}
inline GLint reject(GLint code1, GLint code2){
return GLint(code1 & code2)
}
inline GLint accept (GLint code1, Glint code2){
return GLint(!(code1| code2));
}
GLubyte encode(wcPt2D pt, wcPt2D winMin, wcPt2D winMax)
{
GLubyte code = 0x00;
if(pt.x<winMin.x)
code=code|winLeftBitCode;
if(pt.x>winMax.x)
code=code|winBottomBitCode;
if(pt.y>winMin.y)
code=code|winBottomBitCode;
if(pt.y>winMax.y)
code=code|winTopBitCode;
return (code);
}

void swapPts(wcPt2D * p1, wcPt2D * p2){
wcPt2D tmp;
tmp = *p1;
*p1=*p2;
*p2=tmp;
}

void swapCodes(GLubyte * c1, GLubyte * c2){
GLubyte tmp;
tmp = *c1;
*c1 = *c2;
*c2 = tmp;
}

void linClipCohSuth(wcPt2D winMin, wcPt2D winMax, wcPt2D p1, wcPt2d p2){
GLubyte code1,code2;
GLint done = false, plotLine = false;
GLfloat m;

while(!done){

code1 = encode(p1,winMin,winMax);
code2 = encode(p2,winMin,winMax);
if(accept(code1,code2)){
done=true;
plotLine=true;
}
else
if(reject(code1,code2))
done=true;
else{
if(inside (code1)){
swapPts(&p1,&p2);
swapCodes(&code1,&code2);
}
if(p2.x!=p1.x)
m=(p2.y-p1.y)/(p2.x-p1.x);
if(code1&winLeftBitCode){
p1.y+=(winMin.x -p1.x)*m;
p1.x=winMin.x;
}
else{
if(code1&winRightBitCode){
p1.y+=(winMax.x-p1.x)*m;
p1.x=winMax.x;
}
else{
if(code1&winBottomBitCode){
if(p2.x!=p1.x){
p1.x+=(winMin.y-p1.y)/m;
p1.y=winMin.y;
}
else 
{
if(code1&winTopBitCode){
if(p2.x!=p1.x)
p1.x+=(winMax.y-p1.y)/m;
p1.y=winMax.y
}
}
}
}
}
if(plotLine){
lineBres(round(p1.x),round(p1.y),round(p2.x),round(p2,y);
}

}
