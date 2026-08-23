
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_lm_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lm", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.589773680394269e-01, -1.594078550249482e-01, -1.600639688964832e-01, -1.610870925382748e-01, -1.627317058079943e-01, -1.654795944302132e-01, -1.702854633269650e-01, -1.790719057002608e-01, -1.952366010692800e-01, -2.181771635753863e-01, -1.854154710272808e-01, -8.355787366569299e-02, -7.960961815723132e-02, -7.458891402261973e-02, -6.982035231174899e-02, -6.984295910556919e-02, -9.848937872356905e-02, -2.653257027356962e-01, -1.223549833331223e+00, -1.051888456052961e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_lm_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.969425962398973e-02, -4.715503280904944e-02, -4.345559201970640e-02, -3.803330845722782e-02, -3.001478096240022e-02, -1.800251203768812e-02, 3.134685098700436e-04, 2.878991883860675e-02, 7.302035079915523e-02, 1.309918964106256e-01, 1.077746531983514e-01, -8.203695348040131e-02, -9.047547601288923e-02, -7.576158196186900e-02, -4.758234503466784e-02, 3.566788853385458e-03, 1.143505024439565e-01, 4.012403559680358e-01, 1.639018704840559e+00, 1.402343278832835e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_lm_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.442542567369789e-06, -1.575397246498462e-06, -1.787497199634140e-06, -2.141825056634679e-06, -2.773440475677667e-06, -4.008579761528105e-06, -6.763715113749458e-06, -1.416399295675593e-05, -3.987918561684011e-05, -1.643787024924729e-04, -9.173677926308864e-04, -8.830176095844739e-04, 1.188289675309916e-03, -2.894952528894310e-03, -3.236182687844109e-02, -4.946127336321030e-01, -1.699071283055094e+01, -1.727959613997318e+03, -8.912225382660028e+05, -5.930455910874708e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_lm_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.466035053781006e-03, -1.584150343681554e-03, -1.770310042681757e-03, -2.075645381800377e-03, -2.605884338332103e-03, -3.605012671158969e-03, -5.719587899262432e-03, -1.098959520223349e-02, -2.737665919552899e-02, -9.234793487634919e-02, -3.022577507749646e-01, -1.001874203389047e-01, -4.576374134048309e-02, -2.529652425345724e-01, -1.653983666937246e+00, -1.760885864671448e+01, -3.999961643361909e+02, -2.677407371673635e+04, -1.301510116872707e+07, -8.475878738702504e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_lm_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.740438416413211e-08, 2.004378466933736e-08, 2.454756558588359e-08, 3.282923035232527e-08, 4.978435538668548e-08, 9.028378530642285e-08, 2.109684489721765e-07, 7.046301313460952e-07, 3.875999963611989e-06, 4.182225905508762e-05, 9.044157844620753e-04, 7.973479781615096e-03, 1.099129965231133e-02, 9.126892665466436e-02, 1.652652040409058e+00, 1.037151423178557e+02, 3.044052728739893e+04, 6.854375471572891e+07, 4.047601404247793e+12, 2.048092835808375e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_lm_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.172298460318984e-14, -9.893635570002100e-14, -1.301472005921143e-13, -1.927520785760753e-13, -3.378579630320744e-13, -7.511356925452283e-13, -2.326570340544463e-12, -1.134747974305761e-11, -1.014793652433629e-10, -2.134504556021357e-09, -4.354993698615556e-07, -5.568848712936722e-04, -6.302797298772529e-03, -3.107958002740894e-02, -1.086152730282377e+00, -2.880237842216676e+02, -5.711459903653453e+05, 7.830027101536479e+09, 3.511994522443579e+16, 1.917097091362430e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
