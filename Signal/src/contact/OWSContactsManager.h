#import <Contacts/Contacts.h>
#import <Foundation/Foundation.h>
#import <SignalServiceKit/ContactsManagerProtocol.h>
#import <SignalServiceKit/PhoneNumber.h>
#import "CollapsingFutures.h"
#import "Contact.h"
#import "ObservableValue.h"

/**
 Get latest Signal contacts, and be notified when they change.
 */

#define SIGNAL_LIST_UPDATED @"Signal_AB_UPDATED"

typedef void (^ABAccessRequestCompletionBlock)(BOOL hasAccess);
typedef void (^ABReloadRequestCompletionBlock)(NSArray *contacts);

@interface OWSContactsManager : NSObject <ContactsManagerProtocol>

@property CNContactStore *contactStore;
@property NSCache<NSString *, UIImage *> *avatarCache;

- (ObservableValue *)getObservableContacts;

- (NSArray *)getContactsFromAddressBook:(ABAddressBookRef)addressBook;
- (Contact *)latestContactForPhoneNumber:(PhoneNumber *)phoneNumber;

- (void)verifyABPermission;

- (NSArray<Contact *> *)allContacts;
- (NSArray<Contact *> *)signalContacts;

- (void)doAfterEnvironmentInitSetup;

- (NSString * _Nonnull)displayNameForPhoneIdentifier:(NSString *)identifier;
- (BOOL)nameExistsForPhoneIdentifier:(NSString *)identifier;
- (UIImage * _Nullable)imageForPhoneIdentifier:(NSString *)identifier;

+ (NSComparator)contactComparator;

@end
