#include <cuda_runtime.h>
#include <stdio.h>

#include <xc.h>

int main() {
  xc_func_type func;
  double rho[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
  double sigma[5] = {0.2, 0.3, 0.4, 0.5, 0.6};
  double exc[5];
  double *d_rho, *d_sigma, *d_exc;
  int vmajor, vminor, vmicro, func_id = 1;

  xc_version(&vmajor, &vminor, &vmicro);
  printf("Libxc version: %d.%d.%d\n", vmajor, vminor, vmicro);

  if (xc_func_init_flags(&func, func_id, XC_UNPOLARIZED, XC_FLAGS_ON_DEVICE) != 0) {
    fprintf(stderr, "Functional '%d' not found\n", func_id);
    return 1;
  }

  // Allocate device memory
  cudaMalloc(&d_rho, 5 * sizeof(double));
  cudaMalloc(&d_sigma, 5 * sizeof(double));
  cudaMalloc(&d_exc, 5 * sizeof(double));

  // Copy sample data to device
  cudaMemcpy(d_rho, rho, 5 * sizeof(double), cudaMemcpyHostToDevice);
  cudaMemcpy(d_sigma, sigma, 5 * sizeof(double), cudaMemcpyHostToDevice);

  switch (func.info->family) {
  case XC_FAMILY_LDA:
    xc_lda_exc(&func, 5, d_rho, d_exc);
    break;
  case XC_FAMILY_GGA:
  case XC_FAMILY_HYB_GGA:
    xc_gga_exc(&func, 5, d_rho, d_sigma, d_exc);
    break;
  }

  // Copy result back
  cudaMemcpy(exc, d_exc, 5 * sizeof(double), cudaMemcpyDeviceToHost);

  for (int i = 0; i < 5; i += 1) {
    printf("%lf %lf\n", rho[i], exc[i]);
  }

  cudaFree(d_rho);
  cudaFree(d_sigma);
  cudaFree(d_exc);

  xc_func_end(&func);
}
