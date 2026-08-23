
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ms2b_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.682536676177330e+00, -4.589757306005163e+00, -4.459778016892037e+00, -4.279781822332513e+00, -4.034637761238305e+00, -3.708640606726721e+00, -3.289656434397217e+00, -2.776644418416619e+00, -2.189847187587818e+00, -1.575401974764066e+00, -9.958113257414338e-01, -6.469728584370341e-01, -5.589212388288380e-01, -4.807805903833500e-01, -3.449884711040923e-01, -2.091046847484728e-01, -1.028689638120427e-01, -3.498482169162111e-02, -7.311776028641179e-03, -8.088275563009439e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ms2b_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.115338321500228e+00, -5.989306737035055e+00, -5.812586611951174e+00, -5.567527139732209e+00, -5.233034496078758e+00, -4.786570644834374e+00, -4.208956573341766e+00, -3.492743663815840e+00, -2.653248614348210e+00, -1.747084050868643e+00, -1.060546348267360e+00, -8.173522324566351e-01, -7.393213864431266e-01, -5.883990946500526e-01, -3.795196127838186e-01, -2.216501651477579e-01, -1.212933742234725e-01, -4.574780317779521e-02, -9.739878358985597e-03, -1.078423704458216e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2b_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.438683214682633e-06, -1.565017631736724e-06, -1.766881249585675e-06, -2.104951927436200e-06, -2.711426751509355e-06, -3.915548395428240e-06, -6.696810078755640e-06, -1.475441906471060e-05, -4.708009612786556e-05, -2.363812914069883e-04, -9.264026180691602e-04, -4.742770921959955e-03, -1.303298115607616e-02, -5.943280270764317e-02, -1.466033128923162e-01, -4.386088942242161e-01, -1.178843476595235e+00, -2.040656796802516e+00, -2.493487395603782e+00, -2.756539441128211e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2b_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.474032432724782e-04, 1.603216074914332e-04, 1.808636213809298e-04, 2.149512700528234e-04, 2.749872485014598e-04, 3.896623924941214e-04, 6.329458395491682e-04, 1.214514892272862e-03, 2.728793295007902e-03, 6.126583913866753e-03, 2.534465843208196e-03, 1.204585338448868e-03, 1.161864073130368e-02, 6.273090597054855e-02, 4.661062756093649e-02, 1.689400111326554e-02, 1.175105358282435e-03, 6.078711117201138e-06, 1.816924454541074e-09, 1.818020069413143e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2b_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.665250063671743e-03, -9.934565401966557e-03, -1.031899197411804e-02, -1.085986976058900e-02, -1.159218894643517e-02, -1.247599234389165e-02, -1.311211215947805e-02, -1.161736081553809e-02, -6.227807937498024e-04, 3.090867573219798e-02, -2.539771302675762e-01, -5.509702089494709e-01, -8.902653923335847e-01, -1.482897288522437e+00, -1.097951313876475e+00, 6.413161269283242e+00, 1.464597815784477e+01, -3.648380976375432e+02, -1.123903183765969e+04, -9.309538502723194e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2b_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.519091681715197e-08, -7.691877717860404e-08, -9.741922798824635e-08, -1.363713836584514e-07, -2.196196439152562e-07, -4.292236698559106e-07, -1.089337417268880e-06, -3.879893612289402e-06, -2.077564022554604e-05, -1.575165174793835e-04, 4.884463759931593e-04, 7.347063005542775e-03, -3.332406323842851e-02, 7.295103520556226e-02, -3.728726395547560e+00, -1.470929869224065e+02, -5.157043681297560e+03, -2.556737956163240e+05, -3.492996143229660e+07, -2.855933590492701e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2b_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.063852853331544e-04, 1.176618874076405e-04, 1.358309596973240e-04, 1.665289465833647e-04, 2.219160370238448e-04, 3.311010019025365e-04, 5.722541882148113e-04, 1.179448579017545e-03, 2.880574362003947e-03, 6.853676764566936e-03, -4.698513489229597e-03, 1.698850911650457e-03, 1.515775881504688e-01, 2.152506240064400e-01, 1.964998318981482e+00, 1.003908228457595e+01, 1.561469818710803e+01, 3.925024625452185e+00, 2.182083337815578e-01, 2.963162706678479e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2b_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.164729478933289e-12, 2.712925888701018e-12, 3.748353033499304e-12, 5.949612871831539e-12, 1.148891633215233e-11, 2.918862598943139e-11, 1.081892633075225e-10, 6.650830110624038e-10, 7.788061334416224e-09, 1.776536107244550e-07, -5.301965309981273e-06, 3.705997424295707e-04, -2.362326178043845e-02, 6.955045317076525e-02, 1.077520198573601e+01, 1.813276397056500e+03, 6.346972275447790e+05, 8.142660365474306e+08, 1.271832033286564e+13, 8.051569449872718e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2b_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.071775029182788e-09, -3.619660051929503e-09, -4.577282033498850e-09, -6.397006741450658e-09, -1.028812193913663e-08, -2.009699559131383e-08, -5.103997027170904e-08, -1.816758353021619e-07, -9.524684720199832e-07, -6.035640228038413e-06, 7.139621971672431e-05, -1.528978911994680e-04, 5.542628152424540e-02, 6.479077361778936e-02, -2.971546239932601e+00, -9.643393143165673e+01, -2.008042170205489e+03, -1.843254444687189e+04, -1.369031824765474e+05, -1.546810957527069e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2b_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.384423648146314e-06, 4.858193354969964e-06, 5.623573190493485e-06, 6.921432038432746e-06, 9.274151425032598e-06, 1.393740500642726e-05, 2.427856252654942e-05, 5.013957017722491e-05, 1.181241026271811e-04, 2.042151478251530e-04, -7.115386540032452e-04, -3.848461293026999e-05, -1.235332456465028e-01, -2.849564874291040e-01, 5.936244505580661e-01, 5.109155485063548e+00, 1.048888189410100e+01, 3.654943284996099e+00, 2.715877961846397e-01, 4.452828504215033e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
