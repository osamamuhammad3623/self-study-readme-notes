# Cyber Security Introduction

## Terms
- PoLP: Principle of Least Privilege
- Vulnerability: A weakness in a system (e.g., an unpatched software bug or a weak password).
- Threat: Anything that can exploit a vulnerability (e.g., a hacker, a virus, or even a natural disaster).
- Risk: The intersection of the two. Risk = Threat x Vulnerability.
- IAM: Identity and Access Management.
- RBAC: Role-Based Access Control
- ABAC: Attribute-Based Access Control
- DHCP: Dynamic Host Configuration Protocol
---
## CIA Triad
- Confidentiality: Ensuring that sensitive information is accessed only by authorized individuals. This is often achieved through encryption, access control lists (ACLs), and two-factor authentication (2FA).
- Integrity: Maintaining the consistency, accuracy, and trustworthiness of data over its entire life cycle. This ensures that data cannot be modified by unauthorized people. Common methods include digital signatures and hashing.
- Availability: Ensuring that information and resources are available to users when they need them. This involves maintaining hardware, performing regular updates, and having a plan for Disaster Recovery.
---
- PoLP dictates that a user or process should only have the minimum levels of access—or permissions—necessary to perform its job. This limits the "blast radius" if an account is compromised.

- How apps remember you: servers don't usually keep a constant "open line" to your device. Instead, they use Tokens. JWT: This is the industry standard for app security. When you log in, the server gives your app a JWT. Your app then attaches this "digital badge" to every future request so the server knows it's still you.

---
## Threat Actor vs Threat Vector
Threat Actor (The "Who"): is an individual or group that performs an action with the intent to harm a digital system, network, or person. They are categorized by their motivations, resources, and level of sophistication.
- Cybercriminals: Motivated primarily by financial gain. They often use ransomware or phishing to steal data they can sell.
- State-Sponsored Actors: Highly sophisticated groups funded by governments. Their goals are usually espionage, intellectual property theft, or disrupting critical infrastructure.
- Hacktivists: Individuals who hack to promote a political agenda or social cause.
- Insiders: Employees or contractors who have legitimate access but use it maliciously (or accidentally) to cause harm.
- Script Kiddies: Less experienced individuals who use existing, pre-made tools or scripts to launch attacks, often for thrill-seeking.

Attack Vector (The "How"): is the path, route, or method used by a threat actor to gain access to a system or deliver a malicious payload. If a system is a fortress, the attack vector is the specific door, window, or tunnel the intruder uses to get inside. Common Attack Vectors:
- Phishing: Using deceptive emails or messages to trick users into revealing credentials or downloading malware.
- Unpatched Software: Exploiting known vulnerabilities in operating systems or applications that haven't been updated.

- Credential Stuffing: Using lists of leaked usernames and passwords from one breach to try and gain access to other accounts.

- Man-in-the-Middle (MitM): Intercepting communication between two parties (like on an unsecured public Wi-Fi) to steal data.

- Social Engineering: Manipulating human psychology to convince someone to hand over sensitive information or bypass security protocols.
---
## IAM
IAM is a framework of policies and technologies designed to ensure that the right people have the right access to the right resources at the right time for the right reasons.
IAM is generally broken down into four distinct processes:
- Identification: Claiming who you are (e.g., entering a username).
- Authentication (AuthN): Proving you are who you say you are (e.g., providing a password, a fingerprint, or a code from an app).
- Authorization (AuthZ): Granting or denying permission to do specific things (e.g., a junior engineer can read code, but only a senior engineer can "push" it to production).
- Accountability/Auditing: Tracking what a user did while they were logged in. This creates a "paper trail" for security reviews.

Modern IAM systems use several strategies to keep access secure yet efficient:

- Multi-Factor Authentication (MFA) requires at least two types of evidence (factors) to verify identity. These factors usually fall into three categories:
    - Something you know: A password or PIN.
    - Something you have: A physical key, a smartphone, or a hardware token.
    - Something you are: Biometrics like a fingerprint or facial recognition.
- Single Sign-On (SSO) allows a user to log in once with a single set of credentials to access multiple, independent software systems. This improves productivity and reduces "password fatigue," where users write down dozens of different passwords because they can't remember them all.
- RBAC vs. ABAC
These are the two primary ways to manage Authorization:
    - RBAC: Permissions are tied to a job title. If you are in the "Accounting" group, you automatically get access to the payroll folders.
    - ABAC: Permissions are more granular and based on context. For example: "Allow access to the server only if the user is in the 'Engineering' group and it is between 9:00 AM and 5:00 PM."
---

---
### Resources
- https://youtube.com/playlist?list=PLv7cogHXoVhXvHPzIl1dWtBiYUAL8baHj&si=ciuqp3a9cqxzhkl3
- Gemini :D