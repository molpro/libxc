
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_lspbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lspbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.303321034227976e+00, -4.221598571558403e+00, -4.107194674281462e+00, -3.948945291411328e+00, -3.733790091828519e+00, -3.448440614432222e+00, -3.083248600548713e+00, -2.638998940992983e+00, -2.135011595643816e+00, -1.607618271423781e+00, -1.080698098249645e+00, -6.643881867682839e-01, -5.627372181645169e-01, -4.720093530264366e-01, -3.489759119620256e-01, -2.276927840743268e-01, -1.180616641327496e-01, -3.441691478117849e-02, -1.245974458509814e-04, 6.914845661332990e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_lspbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lspbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.379646245584682e+00, -5.265254042996847e+00, -5.104881302813613e+00, -4.882568192724261e+00, -4.579356800428314e+00, -4.175387187345647e+00, -3.655219525185377e+00, -3.018777476163899e+00, -2.301909309474415e+00, -1.606210224458040e+00, -1.050425542344040e+00, -7.994957459539955e-01, -7.153401792166754e-01, -5.551248597626453e-01, -3.619731259940166e-01, -2.180629971508521e-01, -1.401307024968201e-01, -6.263643688074763e-02, -1.608757570870695e-03, 2.765908775065188e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lspbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lspbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.842506612040195e-06, -4.155146076133576e-06, -4.648344640303443e-06, -5.458014392578447e-06, -6.864637815326386e-06, -9.511295127118669e-06, -1.507496778853030e-05, -2.865785290775111e-05, -6.873620330797469e-05, -2.162053337328381e-04, -1.040090820333466e-03, -6.929411134817793e-03, -1.299402938054255e-02, -2.757492894347172e-02, -9.736202413185721e-02, -4.579802022194649e-01, -1.171727244265966e+00, 3.773786752076317e+01, 3.927802177682148e+02, -3.898710850034770e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lspbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lspbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.222077372238687e-02, -1.278276311101386e-02, -1.363574695363909e-02, -1.496044968559293e-02, -1.708490876987985e-02, -2.064440124936177e-02, -2.694865613440026e-02, -3.873736879994864e-02, -6.029686255014916e-02, -8.367603251841468e-02, -1.224440471014552e-01, -5.636465326976599e-01, -6.790716994629711e-01, -1.165870551320376e+00, -2.128372099925806e+00, 2.652121153146220e+00, 3.669073279999229e+01, -3.571980093164273e+01, -5.219988247808964e+04, 2.149175126992196e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lspbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lspbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.368775875523790e-08, 2.701772743063040e-08, 3.261089022618964e-08, 4.264821074120032e-08, 6.241384269327993e-08, 1.066391834389187e-07, 2.236382105713516e-07, 5.974293332229530e-07, 1.831995372880312e-06, -2.877799441393843e-06, -2.543570192513147e-04, 1.070018891230673e-02, 3.683734166349086e-02, 1.112850726495689e-01, 3.085606702953979e-01, -4.763656386717221e+01, -5.711568961963411e+03, -1.381300787716289e+06, 1.370112726569566e+10, -4.039194309340916e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lspbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lspbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.279507068015322e-14, 6.710496971081956e-14, 9.468108636979601e-14, 1.551071073978209e-13, 3.144050582322139e-13, 8.621829064184611e-13, 3.618016519157619e-12, 2.739255466579922e-11, 4.587357560376323e-10, 2.083720153646848e-08, 2.976544429926978e-06, 3.384514841941286e-04, 1.968631567691387e-03, 2.260728998276904e-02, 1.534978571175112e+00, 5.359669932219034e+02, 4.950262822264933e+05, -4.102644395781157e+08, -4.229598224859442e+15, 1.138708457829609e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
