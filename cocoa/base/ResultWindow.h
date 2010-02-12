/* 
Copyright 2010 Hardcoded Software (http://www.hardcoded.net)

This software is licensed under the "HS" License as described in the "LICENSE" file, 
which should be included with this package. The terms are also available at 
http://www.hardcoded.net/licenses/hs_license
*/

#import <Cocoa/Cocoa.h>
#import "HSOutlineView.h"
#import "StatsLabel.h"
#import "ResultOutline.h"
#import "PyDupeGuru.h"

@interface ResultWindowBase : NSWindowController
{
@protected
    IBOutlet PyDupeGuruBase *py;
    IBOutlet id app;
    IBOutlet NSSegmentedControl *deltaSwitch;
    IBOutlet HSOutlineView *matches;
	IBOutlet NSSegmentedControl *pmSwitch;
	IBOutlet NSTextField *stats;
	IBOutlet NSMenu *columnsMenu;
	IBOutlet NSSearchField *filterField;
    
    NSMutableArray *_resultColumns;
    NSWindowController *preferencesPanel;
    ResultOutline *outline;
    StatsLabel *statsLabel;
}
/* Helpers */
- (void)fillColumnsMenu;
- (NSTableColumn *)getColumnForIdentifier:(NSInteger)aIdentifier title:(NSString *)aTitle width:(NSInteger)aWidth refCol:(NSTableColumn *)aColumn;
- (NSArray *)getColumnsOrder;
- (NSDictionary *)getColumnsWidth;
- (void)initResultColumns;
- (void)restoreColumnsPosition:(NSArray *)aColumnsOrder widths:(NSDictionary *)aColumnsWidth;

/* Actions */
- (IBAction)clearIgnoreList:(id)sender;
- (IBAction)changeDelta:(id)sender;
- (IBAction)changePowerMarker:(id)sender;
- (IBAction)copyMarked:(id)sender;
- (IBAction)deleteMarked:(id)sender;
- (IBAction)exportToXHTML:(id)sender;
- (IBAction)filter:(id)sender;
- (IBAction)ignoreSelected:(id)sender;
- (IBAction)markAll:(id)sender;
- (IBAction)markInvert:(id)sender;
- (IBAction)markNone:(id)sender;
- (IBAction)markSelected:(id)sender;
- (IBAction)moveMarked:(id)sender;
- (IBAction)openClicked:(id)sender;
- (IBAction)openSelected:(id)sender;
- (IBAction)removeMarked:(id)sender;
- (IBAction)removeSelected:(id)sender;
- (IBAction)renameSelected:(id)sender;
- (IBAction)resetColumnsToDefault:(id)sender;
- (IBAction)revealSelected:(id)sender;
- (IBAction)showPreferencesPanel:(id)sender;
- (IBAction)startDuplicateScan:(id)sender;
- (IBAction)switchSelected:(id)sender;
- (IBAction)toggleColumn:(id)sender;
- (IBAction)toggleDelta:(id)sender;
- (IBAction)toggleDetailsPanel:(id)sender;
- (IBAction)togglePowerMarker:(id)sender;

/* Notifications */
- (void)jobCompleted:(NSNotification *)aNotification;
@end
