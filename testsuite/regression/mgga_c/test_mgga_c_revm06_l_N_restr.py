
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_revm06_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.799040912065493e-02, -9.693298934700255e-02, -9.540303289804075e-02, -9.318464342703602e-02, -8.995994470668346e-02, -8.526160182028107e-02, -7.841328864558716e-02, -6.846936585976234e-02, -5.395899168189811e-02, -3.035812023425304e-02, 3.292177059529794e-03, -3.064040967969413e-02, -4.161623847120903e-02, -2.717254652461356e-02, -1.573630567987887e-02, -1.209891953106413e-04, 3.547424370824801e-02, 2.888193315246201e-02, 8.161106419010584e-03, 1.011813304079723e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_revm06_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.213552400112348e-01, -1.191928011405682e-01, -1.159643012564751e-01, -1.110747039693729e-01, -1.035350535587014e-01, -9.168036797318212e-02, -7.282142817961550e-02, -4.365608209095172e-02, -6.285366100251793e-03, 9.441705952887888e-03, -2.527553092089904e-02, -5.981955513937299e-02, -9.135637152198048e-02, -6.960796250017957e-02, -6.895901549957630e-03, -1.948661710942213e-02, 1.270987749324768e-02, 4.669301742770699e-02, 1.561909029587848e-02, 2.090452778324177e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.491287738995642e-07, -3.094028450261161e-07, -4.111571821899855e-07, -5.939764687631831e-07, -9.507945053845530e-07, -1.725803061760448e-06, -3.646124103584629e-06, -9.158907332660713e-06, -2.702200161758984e-05, -8.147038593933639e-05, -7.406741710215966e-05, 5.938384687741313e-03, 9.799868952122209e-03, 2.038657674473242e-04, -7.846714438263636e-02, -3.062919639878858e-01, -1.769745014672910e+00, -8.517036730272261e+01, -3.672838708818659e+03, -4.231100811272204e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.448677268339453e-04, 1.014884083557841e-03, 1.119231771776202e-03, 1.276640836066112e-03, 1.517269872884808e-03, 1.888654535767636e-03, 2.456693062207498e-03, 3.265679310552935e-03, 4.133151331169460e-03, 4.180737868129265e-03, 1.790042775068759e-03, -4.215773761174893e-03, 7.271332994152216e-03, 2.247004308281434e-02, 4.484181893264345e-02, 5.223750021109629e-02, 4.313595874377291e-02, 2.381494530577548e-02, 8.152432212965247e-03, 1.284217559417286e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.225019713990877e-03, -1.357404091414185e-03, -1.569320387389707e-03, -1.923336648272542e-03, -2.549162570851867e-03, -3.736538474771327e-03, -6.168713226562319e-03, -1.137544353088234e-02, -2.079972222798744e-02, -1.824899220542543e-02, 2.937292379221931e-02, -6.534012995173620e-02, 2.363569088986535e-02, -6.601702276128657e-01, -1.897449464779359e+00, 5.416399660156940e+00, -1.381736302542938e+02, -2.003798656936989e+02, 1.952876050246882e+04, 2.320064964810568e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.264548076654803e-08, 2.670537869695697e-08, 3.376227781458592e-08, 4.703910243159447e-08, 7.490965150230462e-08, 1.427511192713655e-07, 3.427598085920078e-07, 1.081412645947428e-06, 4.392943714550023e-06, 1.785197419285122e-05, 1.200648205456407e-04, -9.309371439664378e-03, -4.278793979594824e-02, 3.244361444379965e-01, 2.848945200489957e+00, -4.670400228155807e+00, 9.594608090106645e+03, 7.754386021985826e+05, -3.245089160216396e+09, -3.379980097257895e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.287396494461067e-05, -2.525938824403514e-05, -2.905880488017964e-05, -3.535780933865743e-05, -4.636261920497603e-05, -6.685754759508272e-05, -1.076536848603034e-04, -1.921786376352970e-04, -3.588733435887528e-04, -6.772281009474178e-04, -2.390657353400799e-03, 1.477724657215245e-02, 2.591458451610253e-02, -1.483972118724079e-01, -7.050154409904915e-01, -3.286887994094604e+00, -1.442876619008730e+00, 1.731547656236298e+02, 7.784723407495675e+03, 1.026608107007911e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.615267089511197e-13, -4.539901031979325e-13, -6.282841706378246e-13, -9.970458792165367e-13, -1.914952306235257e-12, -4.778889204391194e-12, -1.693062808415346e-11, -9.415219594631269e-11, -9.091001625837811e-10, -1.844442531029285e-08, -2.441046927373174e-06, -1.073072083380975e-03, 9.163511916218744e-04, -2.214947621941676e-01, -5.533196081783921e+00, -6.673776517878397e+02, -1.339250086022032e+06, -4.809462230476988e+09, -9.915458857076548e+13, -6.452377202270790e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.235157761796815e-10, 3.893818220597855e-10, 5.062198173114139e-10, 7.324603989499481e-10, 1.227283617552498e-09, 2.505905521961190e-09, 6.637256390454259e-09, 2.450512635163787e-08, 1.367871315299798e-07, 1.297981055799060e-06, 2.726473164014635e-05, 6.860029313385729e-04, 1.449859822504733e-03, 1.580520250592118e-01, 2.983166778728146e+00, 1.152883512923758e+02, 9.932390749095373e+03, 4.516372890264510e+06, 2.072394003111745e+10, 1.875443896057239e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.530998565364017e-07, -3.016128962724690e-07, -3.830212704669311e-07, -5.282905359185085e-07, -8.098948426637221e-07, -1.418412012427527e-06, -2.925774010499405e-06, -7.303466786146974e-06, -2.216681760575399e-05, -7.717238092880602e-05, -2.658307192374920e-04, -1.704232097188146e-03, -1.573738846968164e-02, -1.949786622744988e-01, -1.744532579712369e+00, -1.399769000899057e+01, -1.280310724115750e+02, -2.182049950295728e+03, -9.151300996605994e+04, -1.138404563025920e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
