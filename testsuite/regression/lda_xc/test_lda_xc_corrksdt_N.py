
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_corrksdt_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_corrksdt", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.270595102473948e+00, -4.186004893587044e+00, -4.067440766005531e+00, -3.903132477980236e+00, -3.679104157614214e+00, -3.380666987338108e+00, -2.996043570418785e+00, -2.523095533569751e+00, -1.979502511429918e+00, -1.416561769315040e+00, -9.455972314065658e-01, -7.287868704849054e-01, -6.444802239017706e-01, -5.233343222643128e-01, -3.669047189728885e-01, -2.165286600394479e-01, -1.029332834432988e-01, -3.620032935011326e-02, -8.186047547198011e-03, -9.623418469938405e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_corrksdt_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_corrksdt", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.666425419198427e+00, -5.666382044247113e+00, -5.553800066808104e+00, -5.553709437298383e+00, -5.395962598075773e+00, -5.395772395685907e+00, -5.177275408491782e+00, -5.176873636478468e+00, -4.879207245154036e+00, -4.878350355165644e+00, -4.482375646460507e+00, -4.480521471230672e+00, -3.971506006881904e+00, -3.967404606802597e+00, -3.344735874823818e+00, -3.335352208767867e+00, -2.628126843874794e+00, -2.605537749604756e+00, -1.896312266191623e+00, -1.838220846559146e+00, -1.302533289857050e+00, -1.152299893983621e+00, -1.019658533384328e+00, -7.588705555572981e-01, -8.990744809692739e-01, -6.606423144649481e-01, -7.271537491068457e-01, -5.486089863777589e-01, -5.055400665275773e-01, -3.862713209331174e-01, -2.941693176259661e-01, -2.293420913952248e-01, -1.373273733931715e-01, -1.134749840659329e-01, -4.769828213147750e-02, -4.370845582179679e-02, -1.079706660866783e-02, -1.090888951515240e-02, -1.277379354089894e-03, -1.361196289960425e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_corrksdt_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_corrksdt", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.032838581138036e-02, -4.303944401049253e-04, -2.032870331038335e-02, -2.116866986710763e-02, -4.563096638987088e-04, -2.116937494195614e-02, -2.243674031459002e-02, -4.962787189034118e-04, -2.243835540492226e-02, -2.439071859779790e-02, -5.598247688291570e-04, -2.439458706520913e-02, -2.749282133079143e-02, -6.653503578778856e-04, -2.750270164530265e-02, -3.263193567756292e-02, -8.518458686905331e-04, -3.265961397397824e-02, -4.167658243189122e-02, -1.212062353875075e-03, -4.176514538558169e-02, -5.900493747735857e-02, -2.001305052181539e-03, -5.934790426707980e-02, -9.621966171292667e-02, -4.062538056296597e-03, -9.796041679966427e-02, -1.868549814196927e-01, -1.079861840838206e-02, -1.994813980414960e-01, -4.018900677887455e-01, -3.621621467726388e-02, -5.227573001216719e-01, -6.634276648142159e-01, -9.007300316188804e-02, -1.277478502444020e+00, -8.599189211946391e-01, -1.316342489109791e-01, -1.717948691429505e+00, -1.333825459406765e+00, -2.375517482214675e-01, -2.531868006749960e+00, -2.844357313941904e+00, -6.737887399289351e-01, -5.349610452606951e+00, -8.916774178181527e+00, -3.148342316115407e+00, -1.651412601098230e+01, -4.595108440639308e+01, -2.528565130953533e+01, -7.565884901428930e+01, -4.680538219982272e+02, -3.698694779227420e+02, -5.690123114228147e+02, -1.204022697203786e+04, -1.165713638460393e+04, -1.048598207994302e+04, -1.081920459874567e+06, -1.139903892391648e+06, -8.046265413955526e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
