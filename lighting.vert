#version 330 compatibility
out vec2 vST; // texture coords
out vec3 vN; // normal vector
out vec3 vL; // vector from point to light
out vec3 vE; // vector from point to eye
out float vGreenHighlight;
uniform vec3 LIGHT1POSITION;
uniform float greenDistance;
uniform bool inClock;

void main( ){

	

	vST = gl_MultiTexCoord0.st;

	vec4 ECposition = gl_ModelViewMatrix * gl_Vertex;
	if(inClock){
		if(ECposition.x <= greenDistance){
			vGreenHighlight = 1.;
		}else{
			vGreenHighlight = 0.;
		}
	}else{
		vGreenHighlight = 0.;
	}
	vN = normalize( gl_NormalMatrix * gl_Normal ); // normal vector
	vL = LIGHT1POSITION - ECposition.xyz; // vector from the point
	// to the light position
	vE = vec3( 0., 0., 0. ) - ECposition.xyz; // vector from the point
	// to the eye position



	//mess with position down here, all that stuff up there is for lighting.
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	

}