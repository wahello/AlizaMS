#ifndef SHADERS_CORE_H___
#define SHADERS_CORE_H___

const char c3d_vs[] =
"#version 150\n"
"in vec3 v_position;\n"
"in vec3 v_texcoord0;\n"
"out vec3 texcoord0;\n"
"uniform mat4 mvp;\n"
"void main()\n"
"{\n"
"	texcoord0=v_texcoord0\n;"
"	gl_Position=mvp*vec4(v_position,1.0);\n"
"}\n";

const char c3d_fs[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	float t = texture(sampler0,texcoord0).r;\n"
"	if (t >= mparams[0].y && t <= mparams[0].z)\n"
"	{\n"
"		float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"		fragColor=vec4(r*mparams[3].y,r*mparams[3].y,r*mparams[3].y,r*mparams[3].x);\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_clamp[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	float t = texture(sampler0,texcoord0).r;\n"
"	if (t >= mparams[0].y && t <= mparams[0].z)\n"
"	{\n"
"		float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"		fragColor=vec4(r*mparams[3].y,r*mparams[3].y,r*mparams[3].y,1.0);\n"
"	}\n"
"	else if (t > mparams[0].z)\n"
"	{\n"
"		fragColor=vec4(mparams[3].y,mparams[3].y,mparams[3].y,1.0);\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_bb[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	if ((texcoord0.y >= mparams[1].w && texcoord0.y <= mparams[2].x) &&\n"
"	    (texcoord0.x >= mparams[2].y && texcoord0.x <= mparams[2].z))\n"
"	{\n"
"		float t = texture(sampler0,texcoord0).r;\n"
"		if (t >= mparams[0].y && t <= mparams[0].z)\n"
"		{\n"
"			float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"			fragColor=vec4(r*mparams[3].y,r*mparams[3].y,r*mparams[3].y,r*mparams[3].x);\n"
"		}\n"
"		else { discard; }\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_bb_clamp[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	if ((texcoord0.y >= mparams[1].w && texcoord0.y <= mparams[2].x) &&\n"
"	    (texcoord0.x >= mparams[2].y && texcoord0.x <= mparams[2].z))\n"
"	{\n"
"		float t = texture(sampler0,texcoord0).r;\n"
"		if (t >= mparams[0].y && t <= mparams[0].z)\n"
"		{\n"
"			float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"			fragColor=vec4(r*mparams[3].y,r*mparams[3].y,r*mparams[3].y,1.0);\n"
"		}\n"
"		else if (t > mparams[0].z)\n"
"		{\n"
"			fragColor=vec4(mparams[3].y,mparams[3].y,mparams[3].y,1.0);\n"
"		}\n"
"		else { discard; }\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_gradient[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform sampler1D sampler1;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	float t = texture(sampler0,texcoord0).r;\n"
"	if (t >= mparams[0].y && t <= mparams[0].z)\n"
"	{\n"
"		float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"		vec4 color = texture(sampler1, r);\n"
"		fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,r*mparams[3].x);\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_gradient_clamp[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform sampler1D sampler1;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"float t = texture(sampler0,texcoord0).r;\n"
"	if (t >= mparams[0].y && t <= mparams[0].z)\n"
"	{\n"
"		float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"		vec4 color = texture(sampler1, r);\n"
"		fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,1.0);\n"
"	}\n"
"	else if (t > mparams[0].z)\n"
"	{\n"
"		vec4 color = texture(sampler1, 0.999);\n"
"		fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,1.0);\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_gradient_bb[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform sampler1D sampler1;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	if ((texcoord0.y >= mparams[1].w && texcoord0.y <= mparams[2].x) &&\n"
"	    (texcoord0.x >= mparams[2].y && texcoord0.x <= mparams[2].z))\n"
"	{\n"
"		float t = texture(sampler0,texcoord0).r;\n"
"		if (t >= mparams[0].y && t <= mparams[0].z)\n"
"		{\n"
"			float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"			vec4 color = texture(sampler1, r);\n"
"			fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,r*mparams[3].x);\n"
"		}\n"
"		else { discard; }\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_gradient_bb_clamp[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform sampler1D sampler1;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	if ((texcoord0.y >= mparams[1].w && texcoord0.y <= mparams[2].x) &&\n"
"		(texcoord0.x >= mparams[2].y && texcoord0.x <= mparams[2].z))\n"
"	{\n"
"		float t = texture(sampler0,texcoord0).r;\n"
"		if (t >= mparams[0].y && t <= mparams[0].z)\n"
"		{\n"
"			float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"			vec4 color = texture(sampler1, r);\n"
"			fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,1.0);\n"
"		}\n"
"		else if (t > mparams[0].z)\n"
"		{\n"
"			vec4 color = texture(sampler1, 0.999);\n"
"			fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,1.0);\n"
"		}\n"
"		else { discard; }\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_sigm[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	float t = texture(sampler0,texcoord0).r;\n"
"	if (t >= mparams[0].y && t <= mparams[0].z)\n"
"	{\n"
"		float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"		fragColor=vec4(r*mparams[3].y,r*mparams[3].y,r*mparams[3].y,r*mparams[3].x);\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_clamp_sigm[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	float t = texture(sampler0,texcoord0).r;\n"
"	if (t >= mparams[0].y && t <= mparams[0].z)\n"
"	{\n"
"		float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"		fragColor=vec4(r*mparams[3].y,r*mparams[3].y,r*mparams[3].y,1.0);\n"
"	}\n"
"	else if (t > mparams[0].z)\n"
"	{\n"
"		fragColor=vec4(mparams[3].y,mparams[3].y,mparams[3].y,1.0);\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_bb_sigm[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	if ((texcoord0.y >= mparams[1].w && texcoord0.y <= mparams[2].x) &&\n"
"	    (texcoord0.x >= mparams[2].y && texcoord0.x <= mparams[2].z))\n"
"	{\n"
"		float t = texture(sampler0,texcoord0).r;\n"
"		if (t >= mparams[0].y && t <= mparams[0].z)\n"
"		{\n"
"			float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"			fragColor=vec4(r*mparams[3].y,r*mparams[3].y,r*mparams[3].y,r*mparams[3].x);\n"
"		}\n"
"		else { discard; }\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_bb_clamp_sigm[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	if ((texcoord0.y >= mparams[1].w && texcoord0.y <= mparams[2].x) &&\n"
"	    (texcoord0.x >= mparams[2].y && texcoord0.x <= mparams[2].z))\n"
"	{\n"
"		float t = texture(sampler0,texcoord0).r;\n"
"		if (t >= mparams[0].y && t <= mparams[0].z)\n"
"		{\n"
"			float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"			fragColor=vec4(r*mparams[3].y,r*mparams[3].y,r*mparams[3].y,1.0);\n"
"		}\n"
"		else if (t > mparams[0].z)\n"
"		{\n"
"			fragColor=vec4(mparams[3].y,mparams[3].y,mparams[3].y,1.0);\n"
"		}\n"
"		else { discard; }\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_gradient_sigm[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform sampler1D sampler1;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	float t = texture(sampler0,texcoord0).r;\n"
"	if (t >= mparams[0].y && t <= mparams[0].z)\n"
"	{\n"
"		float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"		vec4 color = texture(sampler1, r);\n"
"		fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,r*mparams[3].x);\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_gradient_clamp_sigm[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform sampler1D sampler1;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"float t = texture(sampler0,texcoord0).r;\n"
"	if (t >= mparams[0].y && t <= mparams[0].z)\n"
"	{\n"
"		float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"		vec4 color = texture(sampler1, r);\n"
"		fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,1.0);\n"
"	}\n"
"	else if (t > mparams[0].z)\n"
"	{\n"
"		vec4 color = texture(sampler1, 0.999);\n"
"		fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,1.0);\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_gradient_bb_sigm[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform sampler1D sampler1;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	if ((texcoord0.y >= mparams[1].w && texcoord0.y <= mparams[2].x) &&\n"
"	    (texcoord0.x >= mparams[2].y && texcoord0.x <= mparams[2].z))\n"
"	{\n"
"		float t = texture(sampler0,texcoord0).r;\n"
"		if (t >= mparams[0].y && t <= mparams[0].z)\n"
"		{\n"
"			float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"			vec4 color = texture(sampler1, r);\n"
"			fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,r*mparams[3].x);\n"
"		}\n"
"		else { discard; }\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char c3d_fs_gradient_bb_clamp_sigm[] =
"#version 150\n"
"in vec3 texcoord0;\n"
"uniform sampler3D sampler0;\n"
"uniform sampler1D sampler1;\n"
"uniform vec4 mparams[4];\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	if ((texcoord0.y >= mparams[1].w && texcoord0.y <= mparams[2].x) &&\n"
"		(texcoord0.x >= mparams[2].y && texcoord0.x <= mparams[2].z))\n"
"	{\n"
"		float t = texture(sampler0,texcoord0).r;\n"
"		if (t >= mparams[0].y && t <= mparams[0].z)\n"
"		{\n"
"			float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"			vec4 color = texture(sampler1, r);\n"
"			fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,1.0);\n"
"		}\n"
"		else if (t > mparams[0].z)\n"
"		{\n"
"			vec4 color = texture(sampler1, 0.999);\n"
"			fragColor=vec4(color.x*mparams[3].y,color.y*mparams[3].y,color.z*mparams[3].y,1.0);\n"
"		}\n"
"		else { discard; }\n"
"	}\n"
"	else { discard; }\n"
"}\n";

const char frame_vs[] =
"#version 150\n"
"in vec3 v_position;\n"
"uniform mat4 mvp;\n"
"void main()\n"
"{\n"
"	gl_Position=mvp*vec4(v_position,1.0);\n"
"}\n";

const char frame_fs[] =
"#version 150\n"
"uniform vec4 K;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	fragColor=K;\n"
"}\n";

const char simple_tex_vs[] =
"#version 150\n"
"in vec3 v_position;\n"
"in vec3 v_texcoord0;\n"
"out vec2 texcoord0;\n"
"uniform mat4 mvp;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	texcoord0=v_texcoord0.xy;\n"
"	gl_Position=mvp*vec4(v_position,1.0);\n"
"}\n";

const char simple_tex_fs[] =
"#version 150\n"
"in vec2 texcoord0;\n"
"uniform sampler2D sampler0;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	float color=texture(sampler0,texcoord0).r;\n"
"	fragColor=vec4(color,color,color,1.0);\n"
"}\n";

// sparams[0] eye position
// sparams[1] light direction
const char TBNf_vs0[] =
"#version 150\n"
"in vec3 v_position;\n"
"in vec3 v_normal;\n"
"in vec3 v_texcoord0;\n"
"in vec3 v_tangent;\n"
"uniform mat4 mvp;\n"
"out vec4 position;\n"
"out vec2 texcoord0;\n"
"out vec3 tangent;\n"
"out vec3 normal;\n"
"void main()\n"
"{\n"
"	position=vec4(v_position,1.0);\n"
"	texcoord0=v_texcoord0.xy;\n"
"	normal=v_normal;\n"
"	tangent=v_tangent;\n"
"	gl_Position=mvp*position;\n"
"}\n";

const char TBNf_fs0[] =
"#version 150\n"
"uniform float shininess;\n"
"uniform vec3 sparams[2];\n"
"uniform mat3 modeling;\n"
"uniform mat3 modeling_inv_t;\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"in vec4 position;\n"
"in vec2 texcoord0;\n"
"in vec3 tangent;\n"
"in vec3 normal;\n"
"const vec4 L0c=vec4(1.0,1.0,0.75,1.0);\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"vec4 texcolor=texture(sampler0,texcoord0);\n"
"vec3 Ntbn=texture(sampler1,texcoord0).rgb*2.0-1.0;\n"
"vec3 N=normalize(modeling_inv_t*normal);\n"
"vec3 T=normalize(modeling_inv_t*tangent);\n"
"vec3 B=cross(N,T);\n"
"vec3 Pm=modeling*position.xyz;\n"
"vec3 Vm=normalize(sparams[0]-Pm);\n"
"vec3 L0m=sparams[1];\n"
"vec3 L0tbn;\n"
"vec3 Vtbn;\n"
"L0tbn.x=dot(L0m,T);\n"
"L0tbn.y=dot(L0m,B);\n"
"L0tbn.z=dot(L0m,N);\n"
"Vtbn.x=dot(Vm,T);\n"
"Vtbn.y=dot(Vm,B);\n"
"Vtbn.z=dot(Vm,N);\n"
"vec4 color=L0c*texcolor;\n"
"float diffuse0=clamp(dot(L0tbn,Ntbn),0.0,1.0);\n"
"if (diffuse0>0.0)\n"
"{\n"
"	float specular0=pow(clamp(dot(normalize(L0tbn+Vtbn),Ntbn),0.0,1.0),shininess);\n"
"	color+=L0c*texcolor*diffuse0+L0c*texcolor*specular0;\n"
"}\n"
"fragColor=color;\n"
"}\n";

// sparams[0] eye position
// sparams[1] light direction
const char color_vs[] =
"#version 150\n"
"in vec3 v_position;\n"
"in vec3 v_normal; \n"
"uniform mat4 mvp; \n"
"out vec4 position; \n"
"out vec3 normal; \n"
"void main() \n"
"{\n"
"	position=vec4(v_position,1.0);\n"
"	normal=v_normal;\n"
"	gl_Position=mvp*position;\n"
"}\n";

const char color_fs[] =
"#version 150\n"
"uniform vec4 K[2];\n"
"uniform float shininess;\n"
"uniform vec3 sparams[2];\n"
"uniform mat3 modeling;\n"
"uniform mat3 modeling_inv_t;\n"
"in vec4 position;\n"
"in vec3 normal;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec3 Pm=modeling*position.xyz;\n"
"	vec3 Nm=normalize(modeling_inv_t*normal);\n"
"	vec3 Vm=normalize(sparams[0]-Pm);\n"
"	vec3 Hm0=normalize(Vm+sparams[1]);\n"
"	float diffuse0=max(dot(sparams[1],Nm),0.0);\n"
"	vec4 color=0.2*K[0];\n"
"	if (diffuse0>0.0)\n"
"	{\n"
"		float specular0=pow(max(dot(Hm0,Nm),0.0),shininess);\n"
"		color+=(K[0]*diffuse0+K[1]*specular0);\n"
"	}\n"
"	color.a=1.0;\n"
"	fragColor=color;\n"
"}\n";

const char orientcube_fs[] =
"#version 150\n"
"uniform vec3 K[2];\n"
"uniform vec3 sparams[2];\n"
"in vec4 position;\n"
"in vec3 normal;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec3 Pm=position.xyz;\n"
"	vec3 Nm=normalize(normal);\n"
"	vec3 Vm=normalize(sparams[0]-Pm);\n"
"	vec3 L=normalize(sparams[1]);\n"
"	vec3 Hm0=normalize(Vm+L);\n"
"	float diffuse0=max(dot(L,Nm),0.0);\n"
"	vec3 color=0.2*K[0];\n"
"	if (diffuse0>0.0)\n"
"	{\n"
"		float specular0=pow(max(dot(Hm0,Nm),0.0),10.0);\n"
"		color+=(K[0]*diffuse0+K[1]*specular0);\n"
"	}\n"
"	fragColor=vec4(color.r,color.g,color.b,1.0);\n"
"}\n";

const char mesh_fs[] =
"#version 150\n"
"uniform vec4 K[2];\n"
"uniform vec3 sparams[2];\n"
"in vec4 position;\n"
"in vec3 normal;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec3 Pm=position.xyz;\n"
"	vec3 Nm=normalize(normal);\n"
"	vec3 Vm=normalize(sparams[0]-Pm);\n"
"	vec3 L=normalize(sparams[1]);\n"
"	vec3 Hm0=normalize(Vm+L);\n"
"	float diffuse0=max(dot(L,Nm),0.0);\n"
"	vec4 color=0.2*K[0];\n"
"	if (diffuse0>0.0)\n"
"	{\n"
"		color+=(K[0]*diffuse0);\n"
"	}\n"
"	else\n"
"	{\n"
"		float diffuse1=max(dot(L,-Nm),0.0);\n"
"		color+=(K[1]*diffuse1);\n"
"	}\n"
"	fragColor=vec4(color.r,color.g,color.b,K[0][3]);\n"
"}\n";

const char quad_vs[] =
"#version 150\n"
"in vec2 v_position;\n"
"in vec3 v_texcoord0;\n"
"out vec3 texcoord0;\n"
"void main()\n"
"{\n"
"	texcoord0=v_texcoord0;\n;"
"	gl_Position=vec4(v_position, 0.0, 1.0);\n"
"}\n";

const char fsquad_vs[] =
"#version 150\n"
"in vec2 v_position;\n"
"out vec2 texcoord0;\n"
"void main()\n"
"{\n"
"	texcoord0 = 0.5*v_position + 0.5;\n"
"	gl_Position=vec4(v_position, 0.0, 1.0);\n"
"}\n";

const char fsquad_fs[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"in vec2 texcoord0;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	fragColor=texture(sampler0,texcoord0);\n"
"}\n";

const char zero_vs[] =
"#version 150\n"
"in vec3 v_position;\n"
"in vec3 v_color;\n"
"out vec4 color;\n"
"uniform mat4 mvp;\n"
"void main()\n"
"{\n"
"	color = vec4(v_color.xyz,1.0);\n"
"	gl_Position=mvp*vec4(v_position.xyz,1.0);\n"
"}\n";

const char zero_fs[] =
"#version 150\n"
"in vec4 color;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	fragColor=color;\n"
"}\n";

const char raycast_vs[] =
"#version 150\n"
"in vec3 v_position;\n"
"uniform mat4 mvp;\n"
"out vec4 position;\n"
"void main()\n"
"{\n"
"	position=mvp*vec4(v_position.xyz,1.0);\n"
"	gl_Position= mvp*vec4(v_position.xyz,1.0);\n"
"}\n";

const char raycast_fs[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"uniform sampler3D sampler2;\n"
"uniform vec4 mparams[4];\n"
"in vec4 position;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec2 tc = ((position.xy/position.w)+1.0)/2.0;\n"
"	vec3 back  = texture(sampler0, tc).rgb;\n"
"	vec3 front = texture(sampler1, tc).rgb;\n"
"	vec3 traverse = vec3(front.x-back.x, front.y-back.y, front.z-back.z);\n"
"	vec3 inc = normalize(traverse)\n;"
"	vec3 dim = vec3(mparams[0].x*inc.x,mparams[2].w*inc.y,mparams[1].x*inc.z);\n"
"	float max_dim = length(dim);\n"
"	vec3 delta = inc * (length(traverse)/max_dim);\n"
"	vec3 ray = vec3(0.0);\n"
"	vec4 acc = vec4(0.0);\n"
"	for (int i = 0; i < int(max_dim); i++)\n"
"	{\n"
"		vec3 tmp = ray+back;\n"
"		if (tmp.z >= mparams[1].y && tmp.z <= mparams[1].z)\n"
"		{\n"
"			float t = texture(sampler2, tmp).r;\n"
"			if (t >= mparams[0].y && t <= mparams[0].z)\n"
"			{\n"
"				float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"				float m = r*mparams[3].x;\n"
"				acc.rgb = m*mparams[3].y*vec3(r) + (1.0-m)*acc.rgb;\n"
"				acc.a   = acc.a + (1.0-acc.a)*m;\n"
"			}\n"
"		}\n"
"		ray += delta;\n"
"	}\n"
"	fragColor = acc;\n"
"}\n";

const char raycast_fs_bb[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"uniform sampler3D sampler2;\n"
"uniform vec4 mparams[4];\n"
"in vec4 position;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec2 tc = ((position.xy/position.w)+1.0)/2.0;\n"
"	vec3 back  = texture(sampler0, tc).rgb;\n"
"	vec3 front = texture(sampler1, tc).rgb;\n"
"	vec3 traverse = vec3(front.x-back.x, front.y-back.y, front.z-back.z);\n"
"	vec3 inc = normalize(traverse)\n;"
"	vec3 dim = vec3(mparams[0].x*inc.x,mparams[2].w*inc.y,mparams[1].x*inc.z);\n"
"	float max_dim = length(dim);\n"
"	vec3 delta = inc * (length(traverse)/max_dim);\n"
"	vec3 ray = vec3(0.0);\n"
"	vec4 acc = vec4(0.0);\n"
"	for (int i = 0; i < int(max_dim); i++)\n"
"	{\n"
"		vec3 tmp = ray+back;\n"
"		if ((tmp.z >= mparams[1].y && tmp.z <= mparams[1].z) &&\n"
"			(tmp.y >= mparams[1].w && tmp.y <= mparams[2].x) &&\n"
"			(tmp.x >= mparams[2].y && tmp.x <= mparams[2].z))\n"
"		{\n"
"			float t = texture(sampler2, tmp).r;\n"
"			if (t >= mparams[0].y && t <= mparams[0].z)\n"
"			{\n"
"				float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"				float m = r*mparams[3].x;\n"
"				acc.rgb = m*mparams[3].y*vec3(r) + (1.0-m)*acc.rgb;\n"
"				acc.a   = acc.a + (1.0-acc.a)*m;\n"
"			}\n"
"		}\n"
"		ray += delta;\n"
"	}\n"
"	fragColor = acc;\n"
"}\n";

const char raycast_color_fs[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"uniform sampler3D sampler2;\n"
"uniform sampler1D sampler3;\n"
"uniform vec4 mparams[4];\n"
"in vec4 position;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec2 tc = ((position.xy/position.w)+1.0)/2.0;\n"
"	vec3 back  = texture(sampler0, tc).rgb;\n"
"	vec3 front = texture(sampler1, tc).rgb;\n"
"	vec3 traverse = vec3(front.x-back.x, front.y-back.y, front.z-back.z);\n"
"	vec3 inc = normalize(traverse)\n;"
"	vec3 dim = vec3(mparams[0].x*inc.x,mparams[2].w*inc.y,mparams[1].x*inc.z);\n"
"	float max_dim = length(dim);\n"
"	vec3 delta = inc * (length(traverse)/max_dim);\n"
"	vec3 ray = vec3(0.0);\n"
"	vec4 acc = vec4(0.0);\n"
"	for (int i = 0; i < int(max_dim); i++)\n"
"	{\n"
"		vec3 tmp = ray+back;\n"
"		if (tmp.z >= mparams[1].y && tmp.z <= mparams[1].z)\n"
"		{\n"
"			float t = texture(sampler2, tmp).r;\n"
"			if (t >= mparams[0].y && t <= mparams[0].z)\n"
"			{\n"
"				float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"				float m = r*mparams[3].x;\n"
"				vec3 color = mparams[3].y*texture(sampler3, r).rgb;\n"
"				acc.rgb = m*color + (1.0-m)*acc.rgb;\n"
"				acc.a   = acc.a + (1.0-acc.a)*m;\n"
"			}\n"
"		}\n"
"		ray += delta;\n"
"	}\n"
"	fragColor = acc;\n"
"}\n";

const char raycast_color_fs_bb[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"uniform sampler3D sampler2;\n"
"uniform sampler1D sampler3;\n"
"uniform vec4 mparams[4];\n"
"in vec4 position;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec2 tc = ((position.xy/position.w)+1.0)/2.0;\n"
"	vec3 back  = texture(sampler0, tc).rgb;\n"
"	vec3 front = texture(sampler1, tc).rgb;\n"
"	vec3 traverse = vec3(front.x-back.x, front.y-back.y, front.z-back.z);\n"
"	vec3 inc = normalize(traverse)\n;"
"	vec3 dim = vec3(mparams[0].x*inc.x,mparams[2].w*inc.y,mparams[1].x*inc.z);\n"
"	float max_dim = length(dim);\n"
"	vec3 delta = inc * (length(traverse)/max_dim);\n"
"	vec3 ray = vec3(0.0);\n"
"	vec4 acc = vec4(0.0);\n"
"	for (int i = 0; i < int(max_dim); i++)\n"
"	{\n"
"		vec3 tmp = ray+back;\n"
"		if ((tmp.z >= mparams[1].y && tmp.z <= mparams[1].z) &&\n"
"			(tmp.y >= mparams[1].w && tmp.y <= mparams[2].x) &&\n"
"			(tmp.x >= mparams[2].y && tmp.x <= mparams[2].z))\n"
"		{\n"
"			float t = texture(sampler2, tmp).r;\n"
"			if (t >= mparams[0].y && t <= mparams[0].z)\n"
"			{\n"
"				float r = (t+(-mparams[0].y))/mparams[0].w;\n"
"				float m = r*mparams[3].x;\n"
"				vec3 color = mparams[3].y*texture(sampler3, r).rgb;\n"
"				acc.rgb = m*color + (1.0-m)*acc.rgb;\n"
"				acc.a   = acc.a + (1.0-acc.a)*m;\n"
"			}\n"
"		}\n"
"		ray += delta;\n"
"	}\n"
"	fragColor=acc;\n"
"}\n";

const char raycast_fs_sigm[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"uniform sampler3D sampler2;\n"
"uniform vec4 mparams[4];\n"
"in vec4 position;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec2 tc = ((position.xy/position.w)+1.0)/2.0;\n"
"	vec3 back  = texture(sampler0, tc).rgb;\n"
"	vec3 front = texture(sampler1, tc).rgb;\n"
"	vec3 traverse = vec3(front.x-back.x, front.y-back.y, front.z-back.z);\n"
"	vec3 inc = normalize(traverse)\n;"
"	vec3 dim = vec3(mparams[0].x*inc.x,mparams[2].w*inc.y,mparams[1].x*inc.z);\n"
"	float max_dim = length(dim);\n"
"	vec3 delta = inc * (length(traverse)/max_dim);\n"
"	vec3 ray = vec3(0.0);\n"
"	vec4 acc = vec4(0.0);\n"
"	for (int i = 0; i < int(max_dim); i++)\n"
"	{\n"
"		vec3 tmp = ray+back;\n"
"		if (tmp.z >= mparams[1].y && tmp.z <= mparams[1].z)\n"
"		{\n"
"			float t = texture(sampler2, tmp).r;\n"
"			if (t >= mparams[0].y && t <= mparams[0].z)\n"
"			{\n"
"				float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"				float m = r*mparams[3].x;\n"
"				acc.rgb = m*mparams[3].y*vec3(r) + (1.0-m)*acc.rgb;\n"
"				acc.a   = acc.a + (1.0-acc.a)*m;\n"
"			}\n"
"		}\n"
"		ray += delta;\n"
"	}\n"
"	fragColor = acc;\n"
"}\n";

const char raycast_fs_bb_sigm[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"uniform sampler3D sampler2;\n"
"uniform vec4 mparams[4];\n"
"in vec4 position;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec2 tc = ((position.xy/position.w)+1.0)/2.0;\n"
"	vec3 back  = texture(sampler0, tc).rgb;\n"
"	vec3 front = texture(sampler1, tc).rgb;\n"
"	vec3 traverse = vec3(front.x-back.x, front.y-back.y, front.z-back.z);\n"
"	vec3 inc = normalize(traverse)\n;"
"	vec3 dim = vec3(mparams[0].x*inc.x,mparams[2].w*inc.y,mparams[1].x*inc.z);\n"
"	float max_dim = length(dim);\n"
"	vec3 delta = inc * (length(traverse)/max_dim);\n"
"	vec3 ray = vec3(0.0);\n"
"	vec4 acc = vec4(0.0);\n"
"	for (int i = 0; i < int(max_dim); i++)\n"
"	{\n"
"		vec3 tmp = ray+back;\n"
"		if ((tmp.z >= mparams[1].y && tmp.z <= mparams[1].z) &&\n"
"			(tmp.y >= mparams[1].w && tmp.y <= mparams[2].x) &&\n"
"			(tmp.x >= mparams[2].y && tmp.x <= mparams[2].z))\n"
"		{\n"
"			float t = texture(sampler2, tmp).r;\n"
"			if (t >= mparams[0].y && t <= mparams[0].z)\n"
"			{\n"
"				float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"				float m = r*mparams[3].x;\n"
"				acc.rgb = m*mparams[3].y*vec3(r) + (1.0-m)*acc.rgb;\n"
"				acc.a   = acc.a + (1.0-acc.a)*m;\n"
"			}\n"
"		}\n"
"		ray += delta;\n"
"	}\n"
"	fragColor = acc;\n"
"}\n";

const char raycast_color_fs_sigm[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"uniform sampler3D sampler2;\n"
"uniform sampler1D sampler3;\n"
"uniform vec4 mparams[4];\n"
"in vec4 position;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec2 tc = ((position.xy/position.w)+1.0)/2.0;\n"
"	vec3 back  = texture(sampler0, tc).rgb;\n"
"	vec3 front = texture(sampler1, tc).rgb;\n"
"	vec3 traverse = vec3(front.x-back.x, front.y-back.y, front.z-back.z);\n"
"	vec3 inc = normalize(traverse)\n;"
"	vec3 dim = vec3(mparams[0].x*inc.x,mparams[2].w*inc.y,mparams[1].x*inc.z);\n"
"	float max_dim = length(dim);\n"
"	vec3 delta = inc * (length(traverse)/max_dim);\n"
"	vec3 ray = vec3(0.0);\n"
"	vec4 acc = vec4(0.0);\n"
"	for (int i = 0; i < int(max_dim); i++)\n"
"	{\n"
"		vec3 tmp = ray+back;\n"
"		if (tmp.z >= mparams[1].y && tmp.z <= mparams[1].z)\n"
"		{\n"
"			float t = texture(sampler2, tmp).r;\n"
"			if (t >= mparams[0].y && t <= mparams[0].z)\n"
"			{\n"
"				float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"				float m = r*mparams[3].x;\n"
"				vec3 color = mparams[3].y*texture(sampler3, r).rgb;\n"
"				acc.rgb = m*color + (1.0-m)*acc.rgb;\n"
"				acc.a   = acc.a + (1.0-acc.a)*m;\n"
"			}\n"
"		}\n"
"		ray += delta;\n"
"	}\n"
"	fragColor = acc;\n"
"}\n";

const char raycast_color_fs_bb_sigm[] =
"#version 150\n"
"uniform sampler2D sampler0;\n"
"uniform sampler2D sampler1;\n"
"uniform sampler3D sampler2;\n"
"uniform sampler1D sampler3;\n"
"uniform vec4 mparams[4];\n"
"in vec4 position;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"	vec2 tc = ((position.xy/position.w)+1.0)/2.0;\n"
"	vec3 back  = texture(sampler0, tc).rgb;\n"
"	vec3 front = texture(sampler1, tc).rgb;\n"
"	vec3 traverse = vec3(front.x-back.x, front.y-back.y, front.z-back.z);\n"
"	vec3 inc = normalize(traverse)\n;"
"	vec3 dim = vec3(mparams[0].x*inc.x,mparams[2].w*inc.y,mparams[1].x*inc.z);\n"
"	float max_dim = length(dim);\n"
"	vec3 delta = inc * (length(traverse)/max_dim);\n"
"	vec3 ray = vec3(0.0);\n"
"	vec4 acc = vec4(0.0);\n"
"	for (int i = 0; i < int(max_dim); i++)\n"
"	{\n"
"		vec3 tmp = ray+back;\n"
"		if ((tmp.z >= mparams[1].y && tmp.z <= mparams[1].z) &&\n"
"			(tmp.y >= mparams[1].w && tmp.y <= mparams[2].x) &&\n"
"			(tmp.x >= mparams[2].y && tmp.x <= mparams[2].z))\n"
"		{\n"
"			float t = texture(sampler2, tmp).r;\n"
"			if (t >= mparams[0].y && t <= mparams[0].z)\n"
"			{\n"
"				float r = 1.0 / (1.0 + exp(-6.0*((t-mparams[3].z)/mparams[0].w)));\n"
"				float m = r*mparams[3].x;\n"
"				vec3 color = mparams[3].y*texture(sampler3, r).rgb;\n"
"				acc.rgb = m*color + (1.0-m)*acc.rgb;\n"
"				acc.a   = acc.a + (1.0-acc.a)*m;\n"
"			}\n"
"		}\n"
"		ray += delta;\n"
"	}\n"
"	fragColor=acc;\n"
"}\n";

#endif

