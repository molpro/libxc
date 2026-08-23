
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_1d_soft_HO1D_2_zk():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_soft", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.115841235741764e-01, -4.115838065233974e-01, -4.115829711665204e-01, -4.115807712535667e-01, -4.115749826642111e-01, -4.115597742567407e-01, -4.115199278817980e-01, -4.114160685816083e-01, -4.111479391002679e-01, -4.104673516319215e-01, -4.087866754551012e-01, -4.047943300554784e-01, -3.957146260478409e-01, -3.755469757276552e-01, -3.288064056867129e-01, -2.207855047705874e-01, -7.123447362708490e-02, -5.611531945617735e-03, -4.403741559977837e-05, -8.398245322955611e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_1d_soft_HO1D_2_vrho():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_soft", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.947120211886171e-01, -4.946071951914490e-01, -4.947440520687469e-01, -4.945740950481830e-01, -4.947953260618929e-01, -4.945200167141239e-01, -4.948766831173058e-01, -4.944313282643144e-01, -4.950039545831119e-01, -4.942849863189988e-01, -4.951985826115607e-01, -4.940411325354498e-01, -4.954856757747398e-01, -4.936284116045746e-01, -4.958858479868039e-01, -4.929126264197159e-01, -4.963966488277886e-01, -4.916240165584338e-01, -4.969648982833718e-01, -4.891734978325836e-01, -4.974637629488720e-01, -4.841521787701850e-01, -4.976746860915064e-01, -4.729194093492664e-01, -4.971108793322070e-01, -4.459409329985788e-01, -4.935739780962076e-01, -3.820574975326981e-01, -4.725464819938582e-01, -2.581476620017020e-01, -3.637637833437782e-01, -1.067669999646645e-01, -1.313766330866366e-01, -1.868843369003561e-02, -1.088427558513584e-02, -8.027410654725085e-04, -8.703810699456398e-05, -3.541129217636380e-06, -1.671843703186613e-08, -3.894276055345580e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_1d_soft_HO1D_2_v2rho2():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_soft", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.688099022541563e-02, 0.000000000000000e+00, -3.762729958865446e-02, -3.665302937273662e-02, -5.551115123125783e-17, -3.786304243716937e-02, -3.628819862987120e-02, -5.551115123125783e-17, -3.824828267795732e-02, -3.570952462865262e-02, -2.775557561562891e-17, -3.888031266146680e-02, -3.480478670864268e-02, 0.000000000000000e+00, -3.992384043522296e-02, -3.342246160337881e-02, -2.775557561562891e-17, -4.166443298316458e-02, -3.138619509134438e-02, 8.326672684688674e-17, -4.461519225215521e-02, -2.855362373524484e-02, 0.000000000000000e+00, -4.974654896634123e-02, -2.494820018711030e-02, 0.000000000000000e+00, -5.902610813480685e-02, -2.095178048285928e-02, -8.326672684688674e-17, -7.680819575873654e-02, -1.745714041902852e-02, 5.551115123125783e-17, -1.137328443306788e-01, -1.598382291304079e-02, -4.163336342344337e-17, -1.983421991178074e-01, -1.992775739057076e-02, -5.551115123125783e-17, -4.110851969542062e-01, -4.500480913701915e-02, 1.110223024625157e-16, -9.644851042533890e-01, -2.011943292428964e-01, -3.608224830031759e-16, -2.286677830672510e+00, -1.136603042407133e+00, -1.221245327087672e-15, -4.909392569333276e+00, -4.326603133238763e+00, 8.881784197001252e-16, -9.379749043846044e+00, -1.067657567480535e+01, 1.776356839400250e-15, -1.666429007876141e+01, -2.157479414190840e+01, -7.105427357601002e-15, -2.849324933765290e+01, -3.983718751889887e+01, 2.131628207280301e-14, -4.770083878434752e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
