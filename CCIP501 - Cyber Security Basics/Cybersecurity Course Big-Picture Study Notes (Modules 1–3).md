# Cybersecurity Course: Big-Picture Study Notes (Modules 1–3)

*A single-read overview of your Q&A notes. Read this first so the questions feel familiar, then go back to the Q&A for practice.*

## The whole course in one minute

Information security (InfoSec) is about protecting **information** and everything around it (hardware, software, data, people, procedures, networks) so that it stays **confidential, intact and available**. The course tells one story in four steps:

1. **Module 1: What is it?** Vocabulary, history, the CIA triad, roles and responsibilities.
2. **Module 1 Additional: Who sets the rules?** International standards and frameworks (ISO, NIST, CIS, COBIT, PCI DSS).
3. **Module 2: What are we defending against?** Threats, attacks, malware and software flaws.
4. **Module 3: How do organizations manage defense?** Governance, policy, training (SETA), blueprints and layered architecture.

Three ideas keep coming back, so hold on to them:

- **Security is a process, not a goal.** Perfect security is impossible; you keep balancing protection against usability.
- **Management leads, technology supports.** Top-down support beats technical staff acting alone.
- **People are both the weakest link and the strongest defense.** Training and policy matter as much as firewalls.

---

# PART 1: Module 1, Foundations

## 1.1 What security is

**Security** means being free from danger, plus the actions taken to get there. It does not promise that losses never happen; it makes losses manageable and survivable. **Information security** protects information and the systems that use, store, process and transmit it, using **policy, education/training/awareness, and technology**.

InfoSec has three areas: **management** (planning and overseeing), **data security** (protecting data from unauthorized access, change or destruction) and **network security** (protecting networks and communications). Related "types" of security are physical, personal, operations, communications, national and network security.

**Computer security vs. information security:** computer security started as protecting machines and facilities. InfoSec grew out of it and is much broader: data, people, policies, procedures, networks, everything.

## 1.2 A short history

| When | What happened | Why it matters |
| --- | --- | --- |
| WWII | Code-breaking groups built early computers; Germany used the **Enigma** machine, broken by Polish then British/American cryptanalysts | Birth of cryptography and computer protection. Security was mostly **physical** (theft, espionage, sabotage, classified documents) |
| 1960s | Cold War mainframes; **ARPA** studied networking; **Larry Roberts** led **ARPANET** (ancestor of the Internet); **MULTICS** built by **GE, Bell Labs and MIT** with security built into its core | MULTICS influenced **UNIX** |
| 1968 | Maurice Wilkes on password security in time-sharing systems | Early password thinking |
| **1970** | **RAND Report R-609** by **Willis Ware** | The landmark report: security is more than physical, management must be involved, formal policies are needed, data needs protection, responsibility spreads across levels |
| 1970s–80s | Microprocessors spread; problems with weak passwords, unsafe dial-up, poor user identification and authorization, weak remote-site controls | Security moves from machines to **data and access control** |
| 1975–1984 | FIPS/DES (1975), Protection Analysis (1978), Morris & Thompson passwords and Ritchie on UNIX (1979), **TCSEC** "Rainbow Series" (1982) | Formal standards begin |
| 1984 | Grampp & Morris: four factors in UNIX security | See below |
| 1992 | SIPP protocols, which became **IPsec** | Protecting IP communications |
| 1990s | Networks and the Internet explode on *de facto* standards; security is an afterthought; large firms start building it in | InfoSec emerges as its own profession |
| 2000+ | Millions of networks interconnected; your security depends on others'; attackers shift from hobbyist defacement to **professional crime, extortion and state-sponsored cyberwarfare** | Today's threat landscape |

**Grampp & Morris's four factors:** physical control of premises, management commitment, employee education, administrative procedures.

## 1.3 The CIA triad and the seven characteristics

The **CIA triad** is the foundation:

- **Confidentiality:** only authorized people/systems can see information (encryption, passwords, restricted records).
- **Integrity:** information stays complete and unaltered unless a change is authorized (hashes, protection against tampering).
- **Availability:** authorized users can reach information when needed (backups, backup power, DoS protection).

Quick violation test: someone reads private data = confidentiality. Someone changes a grade = integrity. A server outage locks staff out = availability.

The triad alone is not enough, so the course adds four more, giving **seven critical characteristics**: confidentiality, integrity, availability, **accuracy, authenticity, utility, possession**.

| Characteristic | Plain meaning | Easy-to-confuse partner |
| --- | --- | --- |
| Accuracy | Information is *correct* and error-free | **Integrity** = not improperly *changed*. A wrong date of birth typed in at the start can keep its integrity yet be inaccurate |
| Authenticity | Information is *genuine* and really comes from its claimed source (digital signature) | **Confidentiality** = secrecy. A message can be authentic but public |
| Utility | Information is *usable* for its purpose | An encrypted backup with a lost key is intact but useless |
| Possession | You *hold control or custody* of the information | **Confidentiality.** A thief stealing an encrypted drive takes possession even if they cannot read it |

## 1.4 Key terms: one incident, told as a story

The vocabulary is easiest to remember as a chain of events:

- **Asset:** anything of value that needs protection (a customer database).
- **Vulnerability:** a weakness (the app is open to SQL injection, software is unpatched).
- **Threat:** a potential cause of harm. **Threat source** is where it originates; **threat agent** is the entity that carries it out (a cybercriminal); **threat event** is the specific occurrence.
- **Exploit:** the technique used to take advantage of a vulnerability.
- **Attack:** an *intentional* attempt to compromise an asset.
- **Exposure:** the state of being open to loss because of a vulnerability.
- **Risk:** the possibility of loss when a threat exploits a vulnerability (likelihood × consequence).
- **Loss:** the actual damage (stolen data, downtime).
- **Control / safeguard / countermeasure:** anything that prevents, detects, reduces or responds to risk (firewalls, policies, training, backups).

Other terms: **security posture** (an organization's overall security condition), **protection profile** (security requirements for a type of system), **access** (ability to use a resource), **subject** (the active party requesting access, like an employee) and **object** (the resource being accessed, like a file).

Common traps: *threat* is potential, *attack* is deliberate action. *Risk* is possible harm, *loss* is actual harm. *Attack* is the act, *exploit* is the method.

## 1.5 Models and system components

**CNSS / McCumber Cube:** a 3-D model with three dimensions of three items each, so **3 × 3 × 3 = 27** cells to consider:

- **Goals:** confidentiality, integrity, availability
- **Information states:** storage, processing, transmission
- **Safeguards:** policy, education, technology

Example: protecting private data while it travels = confidentiality + transmission + technology (encryption/TLS).

**An information system has six components:** hardware, software, data, people, procedures, networks. Each has its own weaknesses, and a flaw in one can compromise the whole system.

## 1.6 Balance and implementation approach

Too much security blocks legitimate work; too much access invites attack. Good security **balances protection and access**.

How it gets implemented:

|  | Bottom-up | Top-down |
| --- | --- | --- |
| Starts with | Technical staff / administrators | Senior management |
| Strength | Real technical expertise | Authority, funding, policy, accountability, goals |
| Weakness | Little support or staying power | Needs sustained management commitment |
| Verdict | Often fails | **Generally more successful** (often guided by the **SDLC**) |

## 1.7 Who does what

- **CIO:** senior technology executive advising on information strategy. **CISO:** primarily responsible for assessing, managing and implementing the security program; usually reports to the CIO. The CISO oversees **policy, risk management and technology**.
- **Security project team (7 roles):** champion (senior supporter who gets resources), team leader, security policy developers, risk assessment specialists, security professionals, systems administrators, end users.
- **Data responsibilities (4 roles):**
  - **Data owner:** senior manager accountable for a dataset's security and proper use.
  - **Data trustee:** appointed *by the owner* to oversee management and coordinate with custodians.
  - **Data custodian:** does the technical storing, maintaining and protecting.
  - **Data user:** authorized person who uses data for their job (and can still compromise it by sharing a password or clicking phishing links).
- **Three communities of interest:** information security people (protect assets), IT people (keep systems running), general management (meet organizational goals). They must cooperate.
- **Security is art, science and social science:** *art* because solutions need judgment (the "security artisan"), *science* because technology follows engineering principles, *social science* because human behavior decides success or failure.

---

# PART 2: Standards and Frameworks (Module 1 Additional)

## 2.1 Extra core concepts

- **Cyberspace:** the connected environment of computers, networks, software and data. **Cybersecurity** (ITU-T): the tools, policies, safeguards, training and practices that protect cyberspace and its users.
- **Network security** protects networks; **information security** protects information in any form; **cybersecurity** covers the whole interconnected environment.
- **Accountability:** actions can be traced to a responsible party (logs). **Non-repudiation:** a party cannot credibly deny taking part (digital signatures). **Reliability:** a system works correctly and consistently (different from availability, which is just being reachable).
- **Four cybersecurity dilemmas:** (1) scale and complexity of cyberspace, (2) the evolving nature of threats, (3) user convenience vs. security, (4) the difficulty of measuring costs and benefits, because you cannot easily count attacks that never happened.

## 2.2 Standards vs. best practice, and who publishes what

A **standard** sets requirements or specifications and can support certification (ISO 27001). A **best-practice guideline** recommends effective approaches (ISF Standard of Good Practice).

| Organization | Known for |
| --- | --- |
| **NIST** (US National Institute of Standards and Technology) | Cybersecurity Framework, FIPS, Special Publications (SP) |
| **ISO / IEC** | ISO/IEC 27000 family (ISO leans software, IEC leans hardware/electrical). ISO founded 1946; joint committee **JTC 1** formed 1997 |
| **ITU-T** | Telecom security recommendations |
| **ISF** | Standard of Good Practice (SGP) |
| **CIS** | Critical Security Controls |
| **ISACA** | COBIT |
| **PCI SSC** | PCI DSS |

The **ISF SGP** is built from four sources: ISF research, member experience, national/international standards, and benchmarking. Its management structure runs in a loop: **plan → manage the security function → assess**, and assessment feeds back into planning.

## 2.3 ISO/IEC 27000 family

- An **ISMS** (Information Security Management System) is the coordinated set of policies, procedures and resources an organization uses to manage security risk. A **risk acceptance level** is how much risk the organization will tolerate.
- **ISO/IEC 27001 = requirements** for an ISMS. It is **certifiable** (an independent body audits you). **ISO/IEC 27002 = guidance** on controls. It is a code of practice and is *not* certifiable on its own.
- **27001 clauses 4–10:** Context → Leadership → Planning → Support → Operation → Performance evaluation → Improvement.
- **27002 (lecture edition) has 14 control areas**, including access control, cryptography, supplier relationships, incident management and business continuity.
- Other family members: 27000 (overview/vocabulary), 27003 (implementation), 27004 (measurement), 27005 (risk management), 27006/27007 (auditing and certification bodies), 27017 (cloud), 27018 (personal data in public clouds).
- Related ideas: **internal audit** checks conformity; **management review** is leadership judging whether the ISMS still works; **nonconformity** is a missed requirement; **corrective action** fixes its cause.
- **Three control categories** appear everywhere: **management** (policies, risk assessments), **operational** (day-to-day procedures like training and incident handling), **technical** (firewalls, encryption, access control).

## 2.4 NIST Cybersecurity Framework (CSF)

Three components: **Core, Implementation Tiers, Profiles.**

- **Core: 5 functions:** **Identify** (understand assets and risks) → **Protect** (safeguards) → **Detect** (find events) → **Respond** (act on incidents) → **Recover** (restore services). *(Newer CSF 2.0 adds a sixth, Govern; your slides use five.)*
- **4 Tiers:** 1 Partial → 2 Risk Informed → 3 Repeatable → 4 Adaptive.
- **Profiles:** **Current** profile (where you are) vs. **Target** profile (where you want to be). The difference is the *gap*.
- Other NIST documents: **SP 800-53** (security and privacy controls), **FIPS 200** (minimum requirements, 17 areas), SP 800-100 (manager's handbook), SP 800-55 (measuring security performance), SP 800-27, SP 800-12, SP 800-144 (public cloud).

## 2.5 CIS Critical Security Controls (lecture version: 20)

Prioritized, practical actions grouped as **6 Basic, 10 Foundational, 4 Organizational.**

- **Basic (1–6):** hardware inventory, software inventory, continuous vulnerability management, controlled admin privileges, secure configuration, audit logs.
- **Foundational (7–16):** email/browser protection, malware defense, limiting ports/protocols/services, data recovery, network device configuration, boundary defense, data protection, need-to-know access, wireless access control, account monitoring.
- **Organizational (17–20):** awareness training, application software security, incident response, **penetration tests and red team exercises**.
- **Penetration test:** authorized attack simulation to find and exploit weaknesses within a scope. **Red team:** broader realistic adversary simulation that tests detection and response.

## 2.6 COBIT 5

By **ISACA**; a framework for **governing and managing enterprise IT**. **Governance** decides *whether the right things are being pursued*; **management** decides *how to achieve them*. It has **5 domains and 37 processes**:

| Domain | Meaning | Processes |
| --- | --- | --- |
| EDM | Evaluate, Direct, Monitor (the governance domain) | 5 |
| APO | Align, Plan, Organize | 13 |
| BAI | Build, Acquire, Implement | 10 |
| DSS | Deliver, Service, Support | 6 |
| MEA | Monitor, Evaluate, Assess | 3 |

## 2.7 PCI DSS

For anyone who **stores, processes or transmits payment card data**, maintained by the PCI SSC. The **CDE (Cardholder Data Environment)** is the people, processes and technology touching card data. **Sensitive authentication data** (CVV, PINs, full stripe data) needs the strictest protection.

**6 goals → 12 requirements:**

1. *Secure network:* (1) firewall, (2) no vendor-default passwords.
2. *Protect cardholder data:* (3) protect stored data, (4) encrypt transmission over public networks.
3. *Vulnerability management:* (5) anti-malware, (6) secure systems and applications.
4. *Strong access control:* (7) need-to-know, (8) identify and authenticate, (9) restrict physical access.
5. *Monitor and test:* (10) track and monitor access, (11) regularly test.
6. *Policy:* (12) maintain an information security policy.

## 2.8 ITU-T and the management cycle

**ITU-T** (the telecom standards arm of the UN's International Telecommunication Union) aims for worldwide compatibility. Its security topics include architecture, identity management, **telebiometrics**, authentication and non-repudiation, incident response, application and cloud security.

Cybersecurity management is a **continuous 4-step loop:** plan and select controls → implement and deploy → audit and measure → update and improve. Executives set risk direction; operations teams implement, measure and feed results back.

---

# PART 3: Module 2, The Need for Information Security

## 3.1 Why security exists

Security's mission is to keep information assets **safe and useful**. It has **four functions:** protect the organization's ability to function, protect data, enable safe operation of applications, and safeguard technology assets. Two principles: **business needs come first** (security supports the business, it does not stop it) and **security is a management issue**, not only a technical one. Data must be protected in all three states (transmission, processing, storage), and solutions must grow as the organization grows.

## 3.2 Where threats come from

Threats are **internal** (staff, intentional or accidental) or **external**. The 2015 survey rankings in your notes: top internal threat = **failure to follow policy (66%)**; top external = **unauthorized data collection/sniffing (71%)**; top general threat = **phishing and spoofing (79%)**. Severity was scored 1 (not a threat) to 5 (severe). **CAPEC** (maintained by **MITRE**) catalogs known attack patterns.

## 3.3 The 12 categories of threat

Memorize this list; exam scenarios ask you to match an event to a category:

1. Compromises to **intellectual property**
2. Deviations in **quality of service**
3. **Espionage or trespass**
4. **Forces of nature**
5. **Human error or failure**
6. **Information extortion**
7. **Sabotage or vandalism**
8. **Software attacks**
9. Technical **hardware** failures
10. Technical **software** failures
11. Technological **obsolescence**
12. **Theft**

## 3.4 The categories, explained

**Intellectual property (IP).** Four forms: **trade secrets, copyrights, trademarks, patents.** **Software piracy** is unlicensed copying or use; the **SIIA and BSA** investigate it. About 37% of PC software worldwide was improperly licensed in 2018.

**Quality of service and power.** Failures of the ISP, telecom or electricity. An **SLA** (service level agreement) defines the promised service. Power problems to know:

| Term | Meaning |
| --- | --- |
| Blackout | Total power loss |
| Brownout | Sustained low voltage |
| Sag | Short-term voltage drop |
| Spike | Very brief voltage increase |
| Surge | Longer voltage increase |
| Swell | Temporary voltage above normal |
| Noise / Fault | Interference / abnormal electrical condition |

Defenses: UPS, surge protectors, generators, power conditioning.

**Espionage and trespass.** *Competitive intelligence* is legal (reading a rival's public reports); *industrial espionage* is illegal. **Shoulder surfing** is watching someone enter a PIN or password. **Trespass** is unauthorized entry, physical or digital. Attacker types: *expert hackers* build their own tools; **script kiddies / packet monkeys** use others' tools; **crackers** strip software protections; **phreakers** attack phone systems.

**Password attacks.** *Password cracking* (guessing or analyzing hashes), **brute force** (try every combination), **dictionary** (try likely words and common passwords), **rainbow table** (precomputed hash data, weak against unsalted hashes), and **social engineering**. Strength grows exponentially with length and character variety: combinations = **C^L** (characters available raised to password length). Eight lowercase letters give about 208.8 billion possibilities.

**Forces of nature and human error.** Fire, flood, earthquake, lightning, storms, **ESD** (electrostatic discharge), dust, solar activity; the defense is a **contingency plan**. Human error means accidental disclosure, wrong data entry, accidental deletion, storing data in unprotected places. The fix is training, awareness and clear procedures.

**Social engineering and fraud.** Manipulating people instead of technology. **Phishing** (fake message → fake site → stolen information), **Business Email Compromise** (impersonating an executive to trigger payments), and **advance-fee fraud** (the Nigerian "4-1-9" scam, named after Section 419 of the Nigerian Criminal Code).

**Extortion, ransomware and sabotage.** *Information extortion* demands payment to return or not leak stolen data. **Ransomware** is malware that denies access: **lockscreen** type blocks the computer, **encryption** type scrambles files. **Sabotage** is deliberate destruction (a disgruntled employee deleting a database); **website defacement** is unauthorized changes to a site. Motivated by politics or ideology = **hacktivism**; **cyberterrorism** aims to intimidate a population or government; **cyberwarfare** is state-level operations.

**Malware and software attacks.**

| Type | Key idea |
| --- | --- |
| Virus | Attaches to a file/program; spreads when executed |
| Worm | Spreads **on its own** across networks |
| Trojan horse | Disguised as legitimate software |
| Polymorphic malware | Changes its code to dodge detection |
| Macro virus | Abuses document macros |
| Backdoor | Hidden access that bypasses authentication |
| Zero-day | Exploits a flaw before a fix or detection exists |
| Hoax | False warning about nonexistent malware |
| DoS / DDoS | Overwhelm a target from **one** source / **many** sources |
| Mail bombing, spam | Flooding inboxes / unsolicited bulk mail |
| Sniffer | Captures network traffic |
| Spoofing | Impersonating a trusted source or IP |
| Pharming | Redirects users to a fake site |
| Man-in-the-middle | Intercepts or alters communication between two parties |

Malware spreads through six **replication vectors**: IP scan-and-attack, web browsing, viruses, unprotected shares, mass mail, and SNMP. Famous cases: **ILOVEYOU** (2000), **Code Red** and **Nimda** (2001, Nimda being a *multivector* worm), **SQL Slammer** (2003), **MyDoom** (2004, the costliest at about **$38 billion**), **Conficker** (2009), **Stuxnet**. Remember that ransomware is *not* a communications-interception attack.

**Hardware and software failures.** Hardware can fail terminally or intermittently (the Intel Pentium flaw is the example). **MTBF** is the average time between failures; **AFR** is the percent of devices expected to fail per year. Software ships with bugs because the code is huge; **OWASP** tracks application security risks.

**The "Deadly Sins" of software security.** Common coding and design mistakes:

- **Injection and web flaws:** SQL injection (untrusted input alters a database query), command injection (input reaches an OS command), **XSS** (malicious script runs in a victim's browser), **CSRF/XSRF** (tricks a logged-in browser into a request), HTTP response splitting, hidden form fields and "magic URLs" that are trusted blindly.
- **Memory and logic flaws:** buffer overflow, format string bugs, integer overflow/underflow, unsafe C++ memory handling, race conditions (timing-dependent behavior), improper exception handling, information leakage.
- **Design and operations flaws:** excessive privilege (violating **least privilege**), poor usability, hard-to-update software, unprotected stored data, unprotected network traffic, no **change control**.
- **Crypto flaws:** weak random numbers, incorrect cryptography, misuse of **PKI/SSL** (modern systems use TLS), blindly trusting DNS responses.

**Obsolescence and theft.** Unsupported or outdated technology becomes unreliable and unpatchable, so it needs planned upgrades. **Electronic theft** is harder to detect than physical theft because data can be copied without anything going missing.

---

# PART 4: Module 3, Information Security Management

## 4.1 The Six Ps and governance

Security management rests on policies, standards and practices. **IT management** wants efficient, convenient processing; **security management** wants safe operation. They sometimes pull in opposite directions.

**The Six Ps:** **Planning, Policy, Programs, Protection, People, Project management.** A **program** is ongoing (security awareness); a **project** is temporary with a defined end (installing a new identity system).

**GRC** = Governance, Risk management, Compliance. Governance needs senior management and, where one exists, the **board of directors**.

- **ISO/IEC 27014 gives 6 governance principles:** organization-wide security; risk-based approach; set the direction of investment; ensure conformance with internal and external requirements; foster a security-positive culture; review performance against business outcomes.
- **Five governance processes:** **Evaluate, Direct, Monitor, Communicate, Assure.**
- **Five governance goals:** **strategic alignment, risk management, resource management, performance measurement, value delivery.**

## 4.2 Policy, standard, practice, procedure, guideline

Policy is "organizational law," so it must not contradict real law, be defensible in court, be communicated, understood, accepted and enforced consistently. The password example from the lecture shows the five layers:

| Layer | Role | Password example |
| --- | --- | --- |
| **Policy** | High-level rule: what must be achieved | Use strong passwords and change them regularly |
| **Standard** | Detailed, mandatory requirement for compliance | At least 10 characters with upper/lower case, digits, symbols |
| **Practice** | Commonly accepted way of doing it | Periodic password changes are common |
| **Procedure** | Step-by-step *how-to* | Open settings → choose "change password" → follow prompts |
| **Guideline** | Recommended, non-mandatory advice | Avoid pet names and phone numbers |

## 4.3 The three types of security policy

|  | **EISP** (Enterprise) | **ISSP** (Issue-Specific) | **SysSP** (Systems-Specific) |
| --- | --- | --- | --- |
| Scope | Whole organization, strategic direction | One issue or technology (e.g. email use) | One particular system |
| Audience | Executives, all staff | Affected employees | Administrators and technical staff |
| Notes | Set up with the CIO; assigns responsibilities and penalties | Needs frequent updates | Has **managerial guidance** and **technical specification** forms |

- **EISP's 5 components:** statement of purpose; information security elements; need for security; roles and responsibilities; references to other standards and guidelines.
- **ISSP's 3 management approaches:** independent documents, one comprehensive document, or a **modular** policy.
- **ISSP's 7 components:** statement of policy; authorized access and usage; prohibited use; systems management; violations of policy; policy review and modification; limitations of liability.
- **SysSP technical content:** **ACLs** (who can access which resource, by user, computer, time, duration or file) and **configuration rules** (how a firewall or system responds to traffic or events).

## 4.4 Making policy work

A legally defensible policy needs six things, in order: **Development** (accepted practice, management approval) → **Dissemination** (distributed) → **Reading** → **Comprehension** (understood) → **Compliance** (agreed to) → **Enforcement** (applied uniformly).

After that comes **policy management**, which needs five elements: a responsible policy manager, a review schedule, review procedures, policy and revision dates, and automated policy management (for example, a portal that tracks who acknowledged the latest version).

## 4.5 SETA: Security Education, Training, Awareness

|  | Awareness | Training | Education |
| --- | --- | --- | --- |
| Key question | **What** to recognize and do | **How** to respond | **Why** it works this way |
| Methods | Videos, newsletters, posters | Workshops, hands-on practice | Seminars, theory, reading |
| Assessed by | True/false, multiple choice | Practical exercises | Essays |
| Impact | Short-term | Intermediate | Long-term |

Awareness programs are rarely done but highly valuable. Training can be built in-house, outsourced, taken at conferences or online (**MOOCs** like Coursera).

## 4.6 Blueprints, frameworks and NIST guidance

- A **security framework** gives the structure for designing and selecting controls. A **model** is a recognized framework from a standards body, government agency or industry group. A **blueprint** is *your organization's* detailed plan: which controls, which tasks, in what order. Framework = guidance; blueprint = implementation plan.
- More NIST publications: **SP 800-18** (security plans), **SP 800-30** (risk assessments), **SP 800-37** (Risk Management Framework), **SP 800-39** (managing security risk), **SP 800-50** (awareness and training programs), **SP 800-14** (generally accepted principles, **33 principles**, e.g. security supports the mission, should be cost-effective, responsibilities must be explicit, and should be reassessed regularly).
- **NIST RMF:** build security into systems, monitor them continuously, and give senior leaders the information they need to accept or treat risk.
- **Seven steps to implement the NIST CSF:** (1) Prioritize and scope → (2) Orient → (3) Create current profile → (4) Conduct risk assessment → (5) Create target profile → (6) Determine, analyze and prioritize **gaps** → (7) Implement action plan.
- Other framework sources: **FASP**, **CERT/CC**, and the International Association of Professional Security Consultants.

## 4.7 Security architecture and defense in depth

**Security architecture** layers three control levels: **management** (policy, planning), **operational** (personnel, physical security, SETA, disaster recovery, incident response planning) and **technical** (access control, encryption, firewalls).

**Spheres of security** put information at the center, protected by layers against outside threats (firewalls, monitoring, encryption, backups, updates) and by people-focused measures (training, policy) against inside threats.

**Defense in depth** means many layers, so no single failure exposes everything. A typical stack from outside to inside: external filtering router → **dual-homed proxy server** (two network interfaces, an intermediary between networks) → internal filtering router and **VPN** concentrator → network and host **IDS/IPS** → user education.

- **Security perimeter:** the boundary between protected and less-trusted environments. It stops threats crossing the boundary but does **not** stop insider attacks or on-site physical threats.
- **Security domain:** a group of resources sharing the same trust level and security needs (for example, payroll servers).
- **DMZ (demilitarized zone):** a buffer network holding public-facing systems (web server) separate from the **trusted internal network**.
- **VPN:** a protected connection over another network (remote employee to company network).
- **IDS** detects and alerts; **IPS** detects *and blocks*.

---

# PART 5: Quick Revision Sheet

## Numbers and lists to memorize

| Topic | Fact |
| --- | --- |
| McCumber Cube | 3 × 3 × 3 = **27** cells |
| Critical characteristics of information | **7** |
| Information system components | **6** |
| Security project team roles | **7** |
| Data responsibility roles | **4** (owner, trustee, custodian, user) |
| Communities of interest | **3** |
| ISO 27001 requirement clauses | **7** (clauses 4–10) |
| ISO 27002 control areas (lecture edition) | **14** |
| NIST CSF | **3** components, **5** functions, **4** tiers, **7** implementation steps |
| CIS Controls (lecture version) | **20** = 6 Basic + 10 Foundational + 4 Organizational |
| COBIT 5 | **5** domains, **37** processes (5 / 13 / 10 / 6 / 3) |
| PCI DSS | **6** goals, **12** requirements |
| Module 2 | **4** functions of security, **12** threat categories, **6** replication vectors |
| Module 3 | **6** Ps, **6** governance principles, **5** governance goals, **5** governance processes |
| Policies | **3** types; EISP **5** components; ISSP **3** approaches and **7** components; **6** steps to enforce policy; **5** policy-management elements |
| SETA | **3** parts; short / intermediate / long-term impact |
| NIST SP 800-14 | **33** principles |

## Pairs that exams love to mix up

- **Threat vs. vulnerability:** potential harm vs. an exploitable weakness.
- **Threat vs. attack:** potential vs. deliberate action.
- **Risk vs. loss:** possible vs. actual damage.
- **Integrity vs. accuracy:** not tampered with vs. actually correct.
- **Possession vs. confidentiality:** holding the data vs. keeping it secret.
- **CIO vs. CISO:** information strategy vs. security program.
- **Trustee vs. custodian:** manages on the owner's behalf vs. technically protects the data.
- **ISO 27001 vs. 27002:** certifiable requirements vs. control guidance.
- **Virus vs. worm vs. Trojan:** attaches to a file / spreads alone / pretends to be useful.
- **DoS vs. DDoS:** one source vs. many sources.
- **Standard vs. procedure vs. guideline:** mandatory detail vs. step-by-step vs. optional advice.
- **Awareness vs. training vs. education:** what / how / why.
- **IDS vs. IPS:** alerts vs. alerts and blocks.
- **Governance vs. management:** deciding direction vs. carrying it out.

## Memory aids

- **ISO 27001 clauses:** *Context, Leadership, Planning, Support, Operation, Evaluation, Improvement.*
- **NIST functions:** *Identify, Protect, Detect, Respond, Recover.* **Tiers:** *Partial, Risk-informed, Repeatable, Adaptive.*
- **Policy types:** *EISP = Enterprise, ISSP = Issue, SysSP = System.*
- **Six Ps:** *Planning, Policy, Programs, Protection, People, Project management.*

## Answers to the lecture knowledge checks

**Module 1:** (1) *Being secure and free from danger* (D). (2) **CISO** (B). (3) **Data trustee** (C).

**Module 2:** a short-term drop in power is a **sag**; the interception-attack "except" question's answer is **ransomware**.

**Module 3:** (1) **Standard** (B). (2) **Awareness** (C). (3) **Operational** controls (D).

---

**Study tip:** after one read of this guide, do the Q&A in this order: Module 1 definitions → the seven characteristics and terminology chain → standards numbers (Part 2) → the 12 threat categories → the policy and SETA tables. Those are the areas your own notes flag as highest priority.How we’ll help you reach 85+
Add a measurable result to each role so your impact stays consistent across the full experience section.
Trim broader tools in the skills section to emphasize the stack most aligned with software engineering jobs.
Add outcome data to the volunteer activities and leadership experience to show the scale of your community results.
Pick a template design to match your style, field, and career goals.
