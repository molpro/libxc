
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_xc_b97m_v_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.471483119542602e+00, -5.357212785425232e+00, -5.197285041889316e+00, -4.975852385369141e+00, -4.673479185890378e+00, -4.267312999873714e+00, -3.731334487836779e+00, -3.040522360446315e+00, -2.206279275584095e+00, -1.366525599754647e+00, -7.598809094855953e-01, -5.978186808276117e-01, -6.208784088881812e-01, -5.207118925189379e-01, -3.474428439564431e-01, -2.071058044077855e-01, -1.084799101987188e-01, -4.682086499546950e-02, -1.270361045181661e-02, -1.716775741775538e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_xc_b97m_v_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.032053816367370e+00, -6.865740439972666e+00, -6.637241299914185e+00, -6.330321230413318e+00, -5.931761711437649e+00, -5.437906526031329e+00, -4.853894679397211e+00, -4.150799931587319e+00, -3.197628827967899e+00, -2.044878990093408e+00, -1.190716602667844e+00, -8.888818548114027e-01, -9.502329518552584e-01, -7.482168552972960e-01, -4.437188163939115e-01, -2.554819564323992e-01, -1.207037110933486e-01, -5.795137743141781e-02, -1.636627009294198e-02, -2.256709345790281e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_b97m_v_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.005077924462980e-05, -1.103705672820276e-05, -1.257940394047201e-05, -1.506723883127792e-05, -1.924021179171533e-05, -2.657068229053999e-05, -4.010150105705488e-05, -6.628470308843200e-05, -1.190099380677120e-04, -2.306866395094553e-04, -5.063768447554616e-04, 5.415125399346403e-04, -7.429444817725199e-03, -4.092331301804977e-02, -1.050543400022866e-01, -3.502551068292645e-01, -2.245820672714592e+00, -4.953943264694487e+00, -5.287268641266277e+00, -5.148238100541803e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_b97m_v_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.534993889216415e-02, 1.580412190765198e-02, 1.652392678216960e-02, 1.769088452940088e-02, 1.961065656859627e-02, 2.272340204922997e-02, 2.729470276375232e-02, 3.191569208098109e-02, 3.104054666918319e-02, 2.155886438110084e-02, 1.274462698057565e-02, 9.556071153177609e-03, 6.040853754871061e-02, 9.946775846566860e-02, 6.370767533808148e-02, 4.159038009398925e-02, 1.446785823561185e-02, 8.077449498843589e-04, 1.068650814917206e-05, 2.119250163799983e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_b97m_v_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.294742789269410e-02, -2.327430746580822e-02, -2.362286185959806e-02, -2.386701705993810e-02, -2.371700269090374e-02, -2.280213265454756e-02, -2.218720484262517e-02, -3.231282808622851e-02, -8.577752968328219e-02, -1.954613556778348e-01, -5.097202369827331e-01, -6.613851970226441e-01, -9.944815625389438e-01, -1.536523913104799e+00, -3.935406322615235e+00, -6.253907063087321e+00, -7.238050145916680e+00, -2.924237200936577e+02, -1.617998359894153e+04, -1.826109374495846e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_b97m_v_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.335391032981891e-07, 1.473682918163860e-07, 1.687352390937714e-07, 2.023175382969144e-07, 2.554213553878710e-07, 3.359541017705131e-07, 4.294856749842208e-07, 3.401866876738480e-07, -1.518077050224341e-06, -1.237263246727461e-05, 2.943193561218043e-04, -3.227674106027258e-03, 7.068728800350043e-03, 8.832087808109554e-02, -4.851344185148193e-01, -5.889872543050556e-01, -4.545352068440769e+03, -5.784600134335766e+05, -7.436001029875813e+07, -5.348064361188007e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_b97m_v_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.838239316583644e-05, -9.482608749403162e-05, -1.211231998545351e-04, -1.641837563575372e-04, -2.352321355873342e-04, -3.459346681635748e-04, -4.677085431016981e-04, -3.347951533568800e-04, 8.580971841966852e-04, 2.822784547083268e-03, 5.058369602557268e-03, 1.993184812660452e-02, 8.462794004229449e-02, 7.156674979766416e-02, 1.317769455015353e+00, 9.151636928711819e-02, 3.631763514793514e+01, 7.406690219492552e+01, 1.105074635512529e+02, 1.631827366353972e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_b97m_v_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.383705574586272e-13, -6.184868444131851e-13, -7.487677198615535e-13, -9.685690088980041e-13, -1.351782530794157e-12, -2.022736223342740e-12, -3.156498762798238e-12, -7.121847319926597e-12, -1.214282997950487e-10, -9.037037498158936e-09, -2.312887679252532e-06, -8.750134308014936e-04, -2.956332026025584e-02, -8.018752873921026e-02, -7.244802989351962e-01, 1.600890660583917e+01, 5.163788449550488e+05, 1.761161550514760e+09, 2.682594180749050e+13, 1.503649781620946e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_b97m_v_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.377456942066093e-10, -2.811273489158048e-10, -1.525892883479128e-10, 1.647667031821682e-10, 1.033595294089891e-09, 3.738248854040082e-09, 1.359901872083443e-08, 5.720362698026880e-08, 3.048979323801178e-07, 2.273474928371202e-06, 3.134630502787624e-05, 1.137178443348690e-03, 3.561757408393289e-02, 2.188377452077012e-01, 2.066594934697437e+00, 2.490497613861634e+01, -1.192589024307844e+02, -4.667343460822533e+03, -5.399449286160211e+04, -7.379190545736339e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_b97m_v_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_b97m_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.486227661193550e-06, 2.685384793940790e-06, 2.962637906234708e-06, 3.313412208990738e-06, 3.603432586641184e-06, 3.095620789937965e-06, -1.567864173536434e-06, -2.369129745389634e-05, -9.839716058128919e-05, -2.479657598375936e-04, -5.950978279956166e-04, -3.118439316016566e-03, -8.532645887546923e-02, -4.545412222517902e-01, -2.249929108010141e+00, -3.654615633819065e+00, -3.011035068978705e+01, -7.041409429274785e+01, -1.196507625619986e+02, -1.878563860270497e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
