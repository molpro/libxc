
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_wb97m_v_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.099216173136408e+00, -4.006331528248190e+00, -3.876348378819760e+00, -3.696706568213029e+00, -3.452977104517024e+00, -3.131319747025986e+00, -2.724264262362546e+00, -2.240654796338318e+00, -1.714551924505726e+00, -1.198804175027833e+00, -7.438396576735475e-01, -4.497170205381322e-01, -3.914430213778560e-01, -2.996256153958853e-01, -1.868605507179822e-01, -8.438778304415168e-02, -5.113214899076611e-02, -3.300553211633936e-02, -1.030623198153982e-02, -1.451764521657742e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_wb97m_v_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.667032695365747e+00, -5.538881961554951e+00, -5.358212685066005e+00, -5.105645151173550e+00, -4.756850678176868e+00, -4.284099298414912e+00, -3.663742220841545e+00, -2.899523396556188e+00, -2.063951407164184e+00, -1.300481482361416e+00, -7.421290551943238e-01, -6.085235678764742e-01, -5.525639912124179e-01, -4.019863437447871e-01, -2.421076061414770e-01, -1.054800056276931e-01, -3.205341204475300e-02, -3.725094420641711e-02, -1.311817336218335e-02, -1.904378541016423e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_wb97m_v_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.539506589028145e-06, -3.803254620539630e-06, -4.221090473133772e-06, -4.912974604442188e-06, -6.135129727530519e-06, -8.503392508317615e-06, -1.370773162882572e-05, -2.703591897957967e-05, -6.686157918411267e-05, -2.011246775261299e-04, -8.082397891019915e-04, -2.092066477183592e-03, -2.012359013157375e-03, -7.768217036180428e-03, -3.075120036738530e-02, 5.239449355483745e-02, 2.462649200447581e-01, -2.116793060124126e-01, -5.998928481294693e-01, -8.168462593880972e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_wb97m_v_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.132147956935422e-02, 1.132115998079953e-02, 1.130073026749592e-02, 1.122999937372384e-02, 1.104530282452594e-02, 1.062687956863692e-02, 9.803288698281065e-03, 8.487712405816715e-03, 6.822515533096664e-03, 4.284445214948788e-03, 6.058636558657399e-04, 1.471561997020975e-03, 2.105791443321631e-03, -5.578003585517785e-03, -7.225254734283042e-04, -2.407407431053610e-02, -3.071478152165875e-02, -3.230782452579841e-03, -5.014789016140295e-05, -9.234474764559374e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_wb97m_v_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.364505160627377e-02, -1.445059499599867e-02, -1.570603332448986e-02, -1.772302586383631e-02, -2.108541113383481e-02, -2.690203433744289e-02, -3.715680668586877e-02, -5.476273114942278e-02, -8.326782667659068e-02, -1.280246220808209e-01, -2.663554041889616e-01, -6.438819270526075e-01, -5.669938841310856e-01, -1.056828615961429e+00, -1.123164166260702e+00, -9.626918324151669e+00, 3.283538196564864e+01, 4.894746174797890e+01, -1.194517512509852e+04, -1.525081277869123e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_wb97m_v_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.844387798005319e-08, 2.180525897641383e-08, 2.774884786937808e-08, 3.917386593519343e-08, 6.371681104833918e-08, 1.243664456765299e-07, 3.003482787980487e-07, 8.930112009310344e-07, 2.872772055523877e-06, 3.688920670992393e-07, -1.053555530948803e-04, 9.711399345382399e-03, -7.426635790917599e-03, 1.536031111983939e-01, 1.839180530936449e-01, 6.463712699621015e+00, 1.451669669625160e+03, -1.543329178069234e+04, -8.209487405994700e+06, -8.427632009209023e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_wb97m_v_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.200958552274429e-05, 2.646723393177737e-05, 3.369538612442594e-05, 4.583407932856246e-05, 6.690304798932312e-05, 1.039354973618330e-04, 1.659307992475354e-04, 2.559014656765383e-04, 4.266475048443926e-04, 1.325344725915618e-03, 4.585045394850744e-03, 1.424614212562035e-02, 5.880714669435880e-03, -1.136764550122754e-01, -3.947664409295963e-01, 2.809492847017576e+00, -5.499778839327742e+01, -2.789259041169916e+02, -5.181403481635192e+02, -7.140212518230582e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_wb97m_v_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.924223194937926e-14, 4.346799904150106e-14, 4.938037314376861e-14, 5.672723086918445e-14, 6.238046897215276e-14, 6.164106133825969e-14, 2.677878659755581e-13, 7.267458207848715e-12, 2.487461555589401e-10, 1.424181034281950e-08, 1.740057581377918e-06, -4.827056466616786e-04, 2.952296923331972e-03, -4.884355442284374e-02, -5.318335085791309e-01, -1.302147493046049e+02, -7.919132074471049e+04, 7.831262284586008e+07, 3.048210893797780e+12, 2.385810034720255e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_wb97m_v_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.473993959433484e-11, 7.551834523858709e-11, 7.377101723071780e-11, 6.311844368210228e-11, 2.317427148263840e-11, -1.115874501012310e-10, -5.276120446819636e-10, -1.281395066053710e-09, 6.432559032971311e-09, 1.829927769431631e-07, 1.461171408237483e-06, -1.256101163097376e-04, -4.720877496372524e-04, 3.590353691235909e-05, 4.362705869613218e-01, 1.365219830229510e+00, -6.280739911006635e+02, -9.608220730106377e+03, -9.257206470598005e+04, -1.201044830032529e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_wb97m_v_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_wb97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.102293442431118e-06, -1.227374922146625e-06, -1.424201633937362e-06, -1.742691845822187e-06, -2.272406379316727e-06, -3.165770492417121e-06, -4.641433206739720e-06, -7.106065884820563e-06, -1.432858585114562e-05, -5.071408942291726e-05, -1.526245159669574e-04, -9.404762109000184e-04, 7.549059139017539e-03, 1.091102443011042e-01, 3.286030843854572e-02, -1.250815046781586e+00, 6.095221528129606e+01, 2.837357019723067e+02, 5.619410424815497e+02, 8.185808340742841e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
