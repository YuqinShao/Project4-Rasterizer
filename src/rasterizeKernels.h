// CIS565 CUDA Rasterizer: A simple rasterization pipeline for Patrick Cozzi's CIS565: GPU Computing at the University of Pennsylvania
// Written by Yining Karl Li, Copyright (c) 2012 University of Pennsylvania

#ifndef RASTERIZEKERNEL_H
#define RASTERIZEKERNEL_H

#include <stdio.h>
#include <thrust/random.h>
#include <cuda.h>
#include <cmath>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "cudaMat4.h"

#if CUDA_VERSION >= 5000
    #include <helper_math.h>
#else
    #include <cutil_math.h>
#endif

#define MININFINITE -1000000000000000
#define MAXINFINITE 10000000000000000
#define PHONE 1
#define DEPTH 0
#define BACKFACECULL 1 // 18FPS WITHOUT //26 WITH
#define ANTIA 1 //24 with ANTIA, 26 WITHOUT
#define TEXTURE 1
void kernelCleanup();
void cudaRasterizeCore(uchar4* pos, glm::vec2 resolution, float frame, float* vbo, int vbosize, float* cbo, int cbosize, int* ibo, int ibosize,
	float* nbo, int nbosize
	,glm::mat4 modelM, glm::mat4 viewM, glm::mat4 projectionM
	,glm::vec3* images
	,glm::vec3 cameraPos
	,bool hasTexture
	,glm::vec4* vtbo
	,int vtbosize
	,glm::vec3* texture
	,glm::vec2 textReso);
	

#endif //RASTERIZEKERNEL_H
