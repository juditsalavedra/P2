#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "vad.h"
#include "pav_analysis.h"

const float FRAME_TIME = 10.0F; /* in ms. */
const float N = 30;
const float fm = 16000;
int n = 0;

/* 
 * As the output state is only ST_VOICE, ST_SILENCE, or ST_UNDEF,
 * only this labels are needed. You need to add all labels, in case
 * you want to print the internal state in string format
 */

const char *state_str[] = {
  "UNDEF", "S", "V", "INIT", "MV", "MS"
};

const char *state2str(VAD_STATE st) {
  return state_str[st];
}

/* Define a datatype with interesting features */
typedef struct {
  float zcr;
  float p;
  float am;
} Features;
//tasa de cruces por cero no aporta mucho
//Lo que aporta más es la potencia

/* 
 * TODO: Delete and use your own features!
 */

Features compute_features(const float *x, int N) {
  /*
   * Input: x[i] : i=0 .... N-1 
   * Ouput: computed features
   */
  /* 
   * DELETE and include a call to your own functions
   *
   * For the moment, compute random value between 0 and 1 
   */
  Features feat;
  //asigna un valor aleatorio 
  //feat.zcr = feat.p = feat.am = (float) rand()/RAND_MAX;
  feat.p = compute_power(x, N);
  feat.zcr = compute_zcr(x, N, fm);
  feat.am = compute_am(x, N);
  return feat;
}

/* 
 * TODO: Init the values of vad_data
 */

VAD_DATA * vad_open(float rate, float alpha0, float alpha1) {
  VAD_DATA *vad_data = malloc(sizeof(VAD_DATA));
  vad_data->state = ST_INIT;
  vad_data->sampling_rate = rate;
  vad_data->frame_length = rate * FRAME_TIME * 1e-3;
  vad_data->alpha0=alpha0;
  vad_data->alpha1= alpha1;
  return vad_data;
}

VAD_STATE vad_close(VAD_DATA *vad_data) {
  /* 
   * TODO: decide what to do with the last undecided frames
   */
  VAD_STATE state = vad_data->state;

  free(vad_data);
  return state;
}

unsigned int vad_frame_size(VAD_DATA *vad_data) {
  return vad_data->frame_length;
}

/* 
 * TODO: Implement the Voice Activity Detection 
 * using a Finite State Automata
 */

VAD_STATE vad(VAD_DATA *vad_data, float *x) {

  /* 
   * TODO: You can change this, using your own features,
   * program finite state automaton, define conditions, etc.
   */

  Features f = compute_features(x, vad_data->frame_length);
  //vad_data->last_feature = f.p; /* save feature, in case you want to show */

  //Switch: va a tomar una decisión en función del estado en el que estaba
  //Criterio: 
  vad_data->time += FRAME_TIME;
  switch (vad_data->state) {
  //Estado inicial -> servirá para ver cual es la potencia de ruido
  //Desde la primera trama ya estaremos en silencio. Mantenemos N tramas en INIT para medir la potencia media
  case ST_INIT:
    if(n<N){
      vad_data->p0 += pow(10, f.p/10);
      n = n+1;
    }else{
      vad_data->state = ST_SILENCE;
      vad_data->k0 = 10*log10((vad_data->p0)/N);
      vad_data->p0 = f.p;
      vad_data->k1 = vad_data->k0 + vad_data->alpha0;
      vad_data->k2 = vad_data->k1 + vad_data->alpha1;
      printf("Valor k0: %.2f\n\n", vad_data->k0);
    }
  
    break;

  
  //Lo que más info nos da es la potencia
  //Característica: silencio tiene menos potencia que voz
  //f.p --> feature (de potencia)
  //Si f.p es mayor que 0.95, decido que lo que tengo es potencia
  case ST_SILENCE:
    if (f.p > vad_data->k1){
      vad_data->state = ST_MV;
      vad_data->time = 0;
    }
    printf("S    ");
    break;

  case ST_VOICE:
  
    if(f.p<vad_data->k2){
      vad_data->state = ST_MS;
      vad_data->time = 0;
    }  
          printf("V    ");
    break;

  case ST_MV:
    if(f.p > vad_data->k2){
      vad_data->state = ST_VOICE;
      vad_data->time = 0;
    }else if(f.p < vad_data->k1 || (f.p > vad_data->k1 && vad_data->time > vad_data->tMAX)){
      vad_data->state = ST_SILENCE;
      vad_data->time = 0;
    }
    printf("MV   ");
    //Si es més gran que k1 durant t<tMAX i més petit que k2 es manté a Maybe Voice
    break;

  case ST_MS:
    if(f.p < vad_data->k1){
      vad_data->state = ST_SILENCE;
      vad_data->time = 0;
    }else if(f.p < vad_data->k2 && vad_data->time < vad_data->tMAX){
      vad_data->state = ST_VOICE;
      vad_data->time = 0;
    }
    printf("MS   ");
    break;


  case ST_UNDEF:
    break;
  }

  vad_data->last_feature = f.p; /* save feature, in case you want to show */
  printf("Valor f.p: %.2f\n", vad_data->last_feature);

  if (vad_data->state == ST_SILENCE ||
      vad_data->state == ST_VOICE)
    return vad_data->state;
  else
    return ST_UNDEF;
}

void vad_show_state(const VAD_DATA *vad_data, FILE *out) {
  fprintf(out, "%d\t%f\n", vad_data->state, vad_data->last_feature);
}
