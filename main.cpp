#include <iostream>
#include <string>

using namespace std;

struct User {
    int userId;
    string userName;
    string userContact;
    string userRole;
    string volunteerArea;
};

struct DisasterIncident {
    int disasterId;
    string disasterType;
    string disasterLocation;
    string affectedPeople;
    string helpNeeded;
};

struct EmergencyAlert {
    int alertId;
    string callerId;
    string alertLocation;
    string alertType;
};

struct ReliefResource {
    int resourceId;
    string resourceName;
    int resourceQty;
};

struct ReliefAllocation {
    int allocationId;
    string recipientId;
    string reliefItem;
    int allocatedQty;
};

struct VolunteerAssignment {
    int assignmentId;
    string volunteerName;
    string deploymentArea;
};

User userList[100];
int totalUsers = 0;

DisasterIncident disasterList[100];
int totalDisasters = 0;

EmergencyAlert emergencyList[100];
int totalEmergencies = 0;

ReliefResource resourceList[100];
int totalResources = 0;

ReliefAllocation allocationList[100];
int totalAllocations = 0;

VolunteerAssignment assignmentList[100];
int totalAssignments = 0;

int main() {
    int systemChoice = 0;

    while (systemChoice != 3) {
        cout << "=================================\n";
        cout << "     DISASTER RELIEF SYSTEM\n";
        cout << "=================================\n";
        cout << "1. User Portal\n";
        cout << "2. Admin Portal\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> systemChoice;

        if (systemChoice == 1) {
            int userMenuChoice = 0;
            while (userMenuChoice != 4) {
                cout << "\n===== USER MENU =====\n";
                cout << "1. Register User\n";
                cout << "2. Report Disaster\n";
                cout << "3. Emergency Call\n";
                cout << "4. Back\n";
                cout << "Enter Choice: ";
                cin >> userMenuChoice;

                if (userMenuChoice == 1) {
                    cout << "\n===== REGISTER USER =====\n";
                    totalUsers++;
                    userList[totalUsers].userId = totalUsers;
                    cout << "Enter Name: ";
                    cin >> userList[totalUsers].userName;
                    cout << "Enter Contact: ";
                    cin >> userList[totalUsers].userContact;

                    cout << "1. Victim\n";
                    cout << "2. Volunteer\n";
                    cout << "Enter Choice: ";
                    int roleChoice;
                    cin >> roleChoice;

                    if (roleChoice == 1) {
                        userList[totalUsers].userRole = "Victim";
                        userList[totalUsers].volunteerArea = "";
                    } else {
                        userList[totalUsers].userRole = "Volunteer";
                        cout << "Enter Volunteer Area: ";
                        cin >> userList[totalUsers].volunteerArea;
                    }
                    cout << "User registered successfully!\n";
                } else if (userMenuChoice == 2) {
                    cout << "\n===== REPORT DISASTER =====\n";
                    totalDisasters++;
                    disasterList[totalDisasters].disasterId = totalDisasters;
                    cout << "Enter Disaster Type: ";
                    cin >> disasterList[totalDisasters].disasterType;
                    cout << "Enter Location: ";
                    cin >> disasterList[totalDisasters].disasterLocation;
                    cout << "Enter Affected People: ";
                    cin >> disasterList[totalDisasters].affectedPeople;
                    cout << "Enter Help Needed: ";
                    cin >> disasterList[totalDisasters].helpNeeded;
                    cout << "Disaster reported successfully!\n";
                } else if (userMenuChoice == 3) {
                    cout << "\n===== EMERGENCY CALL =====\n";
                    totalEmergencies++;
                    emergencyList[totalEmergencies].alertId = totalEmergencies;
                    cout << "Enter User ID: ";
                    cin >> emergencyList[totalEmergencies].callerId;
                    cout << "Enter Location: ";
                    cin >> emergencyList[totalEmergencies].alertLocation;
                    cout << "Enter Emergency Type: ";
                    cin >> emergencyList[totalEmergencies].alertType;
                    cout << "\nEMERGENCY ALERT!\n";
                    cout << "Admin Team has been informed.\n";
                } else if (userMenuChoice == 4) {
                    cout << "\nGoing back...\n\n";
                }
            }
        } else if (systemChoice == 2) {
            cout << "\n===== ADMIN LOGIN =====\n";
            string adminUser, adminPass;
            cout << "Username: ";
            cin >> adminUser;
            cout << "Password: ";
            cin >> adminPass;

            if (adminUser == "admin" && adminPass == "admin123") {
                cout << "\nLogin successful!\n";
                int adminMenuChoice = 0;

                while (adminMenuChoice != 9) {
                    cout << "\n===== ADMIN MENU =====\n";
                    cout << "1. Register User\n";
                    cout << "2. View Disasters\n";
                    cout << "3. View Users\n";
                    cout << "4. Add Resource\n";
                    cout << "5. Assign Relief\n";
                    cout << "6. Assign Volunteer\n";
                    cout << "7. View Emergency Calls\n";
                    cout << "8. Government Ministry Report\n";
                    cout << "9. Logout\n";
                    cout << "\nEnter Choice: ";
                    cin >> adminMenuChoice;

                    if (adminMenuChoice == 1) {
                        cout << "\n===== REGISTER USER =====\n";
                        totalUsers++;
                        userList[totalUsers].userId = totalUsers;
                        cout << "Enter Name: ";
                        cin >> userList[totalUsers].userName;
                        cout << "Enter Contact: ";
                        cin >> userList[totalUsers].userContact;

                        cout << "1. Victim\n";
                        cout << "2. Volunteer\n";
                        cout << "Enter Choice: ";
                        int roleChoice;
                        cin >> roleChoice;

                        if (roleChoice == 1) {
                            userList[totalUsers].userRole = "Victim";
                            userList[totalUsers].volunteerArea = "";
                        } else {
                            userList[totalUsers].userRole = "Volunteer";
                            cout << "Enter Volunteer Area: ";
                            cin >> userList[totalUsers].volunteerArea;
                        }
                        cout << "User registered successfully!\n";
                    } else if (adminMenuChoice == 2) {
                        cout << "\n===== DISASTERS =====\n";
                        for (int i = 1; i <= totalDisasters; i++) {
                            cout << "\nID:\n" << disasterList[i].disasterId;
                            cout << "\nType:\n" << disasterList[i].disasterType;
                            cout << "\nLocation:\n" << disasterList[i].disasterLocation;
                            cout << "\nAffected\nPeople: " << disasterList[i].affectedPeople;
                            cout << "\nHelp:\n" << disasterList[i].helpNeeded << "\n";
                        }
                    } else if (adminMenuChoice == 3) {
                        cout << "\n===== USERS =====\n";
                        for (int i = 1; i <= totalUsers; i++) {
                            cout << "\nID:\n" << userList[i].userId;
                            cout << "\nName:\n" << userList[i].userName;
                            cout << "\nRole:\n" << userList[i].userRole;
                            cout << "\nContact:\n" << userList[i].userContact << "\n";
                        }
                    } else if (adminMenuChoice == 4) {
                        cout << "\n===== ADD RESOURCE =====\n";
                        totalResources++;
                        resourceList[totalResources].resourceId = totalResources;
                        cout << "Enter Resource Name: ";
                        cin >> resourceList[totalResources].resourceName;
                        cout << "Enter Quantity: ";
                        cin >> resourceList[totalResources].resourceQty;
                        cout << "Resource added successfully!\n";
                    } else if (adminMenuChoice == 5) {
                        cout << "\n===== ASSIGN RELIEF =====\n";
                        totalAllocations++;
                        allocationList[totalAllocations].allocationId = totalAllocations;
                        cout << "Enter Victim ID: ";
                        cin >> allocationList[totalAllocations].recipientId;
                        cout << "Enter Item: ";
                        cin >> allocationList[totalAllocations].reliefItem;
                        cout << "Enter Quantity: ";
                        cin >> allocationList[totalAllocations].allocatedQty;

                        for (int i = 1; i <= totalResources; i++) {
                            if (resourceList[i].resourceName == allocationList[totalAllocations].reliefItem) {
                                resourceList[i].resourceQty -= allocationList[totalAllocations].allocatedQty;
                            }
                        }
                        cout << "Relief assigned successfully!\n";
                    } else if (adminMenuChoice == 6) {
                        cout << "\n===== ASSIGN VOLUNTEER =====\n";
                        totalAssignments++;
                        assignmentList[totalAssignments].assignmentId = totalAssignments;
                        int targetVolunteerId;
                        cout << "Enter Volunteer ID: ";
                        cin >> targetVolunteerId;

                        for (int i = 1; i <= totalUsers; i++) {
                            if (userList[i].userId == targetVolunteerId) {
                                assignmentList[totalAssignments].volunteerName = userList[i].userName;
                            }
                        }
                        cout << "Enter Area: ";
                        cin >> assignmentList[totalAssignments].deploymentArea;
                        cout << "Volunteer assigned successfully!\n";
                    } else if (adminMenuChoice == 7) {
                        cout << "\n===== EMERGENCY CALLS =====\n";
                        for (int i = 1; i <= totalEmergencies; i++) {
                            cout << "\nCall\nID: " << emergencyList[i].alertId;
                            cout << "\nUser\nID: " << emergencyList[i].callerId;
                            cout << "\nLocation:\n" << emergencyList[i].alertLocation;
                            cout << "\nType:\n" << emergencyList[i].alertType << "\n";
                        }
                    } else if (adminMenuChoice == 8) {
                        cout << "\n=================================\n";
                        cout << " GOVERNMENT MINISTRY REPORT\n";
                        cout << "=================================\n";
                        cout << "\nTotal\nUsers: " << totalUsers;
                        cout << "\nTotal\nDisasters: " << totalDisasters;
                        cout << "\nTotal\nEmergencies: " << totalEmergencies;
                        cout << "\nTotal\nVolunteers: " << totalAssignments;
                        cout << "\nTotal\nResources: " << totalResources;
                        cout << "\nTotal\nRelief Packages: " << totalAllocations << "\n";

                        cout << "\n===== DISASTERS =====\n";
                        for (int i = 1; i <= totalDisasters; i++) {
                            cout << "\nID:\n" << disasterList[i].disasterId;
                            cout << "\nType:\n" << disasterList[i].disasterType;
                            cout << "\nLocation:\n" << disasterList[i].disasterLocation;
                            cout << "\nAffected\nPeople: " << disasterList[i].affectedPeople;
                            cout << "\nHelp:\n" << disasterList[i].helpNeeded << "\n";
                        }

                        cout << "\n===== EMERGENCIES =====\n";
                        for (int i = 1; i <= totalEmergencies; i++) {
                            cout << "\nID:\n" << emergencyList[i].alertId;
                            cout << "\nUser\nID: " << emergencyList[i].callerId;
                            cout << "\nLocation:\n" << emergencyList[i].alertLocation;
                            cout << "\nType:\n" << emergencyList[i].alertType << "\n";
                        }

                        cout << "\n===== VOLUNTEERS =====\n";
                        for (int i = 1; i <= totalAssignments; i++) {
                            cout << "\nID:\n" << assignmentList[i].assignmentId;
                            cout << "\nName:\n" << assignmentList[i].volunteerName;
                            cout << "\nArea:\n" << assignmentList[i].deploymentArea << "\n";
                        }

                        cout << "\n===== RESOURCES =====\n";
                        for (int i = 1; i <= totalResources; i++) {
                            cout << "\nID:\n" << resourceList[i].resourceId;
                            cout << "\nName:\n" << resourceList[i].resourceName;
                            cout << "\nQuantity:\n" << resourceList[i].resourceQty << "\n";
                        }

                        cout << "\n===== RELIEF =====\n";
                        for (int i = 1; i <= totalAllocations; i++) {
                            cout << "\nID:\n" << allocationList[i].allocationId;
                            cout << "\nVictim\nID: " << allocationList[i].recipientId;
                            cout << "\nItem:\n" << allocationList[i].reliefItem;
                            cout << "\nQuantity:\n" << allocationList[i].allocatedQty << "\n";
                        }

                        cout << "\nReport\nprepared for Government Ministry.\n";
                    } else if (adminMenuChoice == 9) {
                        cout << "\nLogging out...\n\n";
                    }
                }
            } else {
                cout << "\nInvalid Credentials. Access Denied.\n\n";
            }
        } else if (systemChoice == 3) {
            cout << "\nGoodbye!\n";
        }
    }

    return 0;
}
